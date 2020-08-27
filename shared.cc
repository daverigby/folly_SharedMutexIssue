#include <folly/ThreadLocal.h>

FOLLY_EXPORT void setThreadLocalViaShared(folly::ThreadLocal<int>& localInt) {
        *localInt = 1;
}
