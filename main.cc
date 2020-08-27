#include <folly/ThreadLocal.h>

FOLLY_EXPORT void setThreadLocalViaShared(folly::ThreadLocal<int>&);

int main() {
    // Define one thread-local from the main module.
    folly::ThreadLocal<int> localInt1;

    // Also set the same thread-local `localInt` via a dll.
    setThreadLocalViaShared(localInt1);
}
