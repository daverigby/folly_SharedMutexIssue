#include <folly/SharedMutex.h>
#include <cstdio>
#include <shared_mutex>

FOLLY_EXPORT void lockViaSharedLibrary(MUTEX& mutex) {
    for (int i = 0; ; i++) {
        if ((i % 128) == 0) {
            fprintf(stderr, "Thread [%p] %i\n", &i, i);
        }
        mutex.lock_shared();
        mutex.unlock_shared();
    }
}
