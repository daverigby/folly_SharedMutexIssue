#include "shared.h"

#include <folly/synchronization/Baton.h>
#include <iostream>

//folly::ThreadLocal<int, TestTag> localInt;

std::thread makeThread(Obj& object, folly::Baton<>& shutdown) {
    folly::Baton<> baton;
    std::thread thread([&object, &baton, &shutdown] {
        *object.localInt = 1;
        baton.post();
        // Keep the thread-local around until shutdown.
        shutdown.wait();
    });
    // Ensure thread has set the thread-local before returning.
    baton.wait();
    return std::move(thread);
}


int main() {
    Obj object;

    folly::Baton<> shutdown;

    // Set thread-local of 'object' using a thread created via a dll.
//    auto thread1 = makeThreadViaShared(shutdown);
    auto thread1 = makeThread(object, shutdown);

#if 1
    // then via a thread created here.
    folly::Baton<> localSet;
    auto thread2 = std::thread([&object, &localSet, &shutdown] {
        *object.localInt = 2;
        localSet.post();
        shutdown.wait();
    });


    // Wait for local to be set everywhere, then sum up values. Should
    // be 1 + 2.
    localSet.wait();
#endif

    *object.localInt = 2;

    int total = 0;
    for (const auto& i : object.localInt.accessAllThreads()) {
        total += i;
    }
    std::cerr << "total:" << total << "\n";

    if (total != 1 + 2) {
        std::abort();
    }

    shutdown.post();
    thread1.join();
    thread2.join();
}
