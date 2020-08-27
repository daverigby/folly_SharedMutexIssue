#include "shared.h"

#include <functional>
#include <folly/ThreadLocal.h>

std::thread makeThreadViaShared(folly::Baton<>& shutdown) {
    folly::Baton<> baton;
    std::thread thread([&baton, &shutdown] {
//        *localInt = 1;
        baton.post();
        // Keep the thread-local around until shutdown.
        shutdown.wait();
    });
    // Ensure thread has set the thread-local before returning.
    baton.wait();
    return std::move(thread);
}
