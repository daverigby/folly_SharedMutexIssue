#include <folly/SharedMutex.h>
#include <shared_mutex>
#include <thread>

FOLLY_EXPORT void lockViaSharedLibrary(MUTEX&);

int main() {
    MUTEX mutex;

    // Create two additional threads which repeatedly locks / unlocks
    // via a shared library.
    std::thread shared1{[&mutex](){
            lockViaSharedLibrary(mutex);
        }};
    std::thread shared2{[&mutex](){
            lockViaSharedLibrary(mutex);
        }};

    while (true) {
        mutex.lock();
        mutex.unlock();
    };

    shared1.join();
    shared2.join();
}
