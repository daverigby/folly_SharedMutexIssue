#include "config.h"

#include <cstdio>

FOLLY_EXPORT void lockViaSharedLibrary(Mutex& mutex) {
    for (int i = 0; ; i++) {
        if ((i % 128) == 0) {
            fprintf(stderr, "Thread [%p] %i\n", &i, i);
        }
        mutex.lock_shared();
        mutex.unlock_shared();
    }
}
