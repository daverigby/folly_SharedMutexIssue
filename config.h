#include <folly/SharedMutex.h>
#include <shared_mutex>

// Test hangs (deadlocks) with Mutex = folly::SharedMutex in <10s.
// Adding my own tag which has external (default) visibility, ensuring
// SharedMutexImpl<false, MyTag, ...>::deferredReaders has weak
// linkage) runs successfully.
#if defined(EXPLICIT_TAG)
struct FOLLY_EXPORT MyTag {};
using Mutex = folly::SharedMutexImpl<false, MyTag>;
#else
using Mutex = folly::SharedMutex;;
#endif
