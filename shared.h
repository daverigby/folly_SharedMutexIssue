#include <folly/synchronization/Baton.h>
#include <folly/CPortability.h>
#include <folly/ThreadLocal.h>
#include <thread>

struct FOLLY_EXPORT Obj {
    folly::ThreadLocal<int, Obj> localInt;
};

//FOLLY_EXPORT std::thread makeThreadViaShared(folly::Baton<>&);

