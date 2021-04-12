project(StaticMetaSingleton LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(folly)

# Test hangs (deadlocks) with MUTX=folly::SharedMutex in <10s.
# With std::shared_mutex runs fine for at least 5 minutes.
add_compile_definitions(MUTEX=folly::SharedMutex)
#add_compile_definitions(MUTEX=std::shared_mutex)

add_executable(main main.cc)
target_link_libraries(main shared Folly::folly)

add_library(shared SHARED shared.cc)
target_link_libraries(shared Folly::folly)
set_target_properties(shared PROPERTIES CXX_VISIBILITY_PRESET hidden)
