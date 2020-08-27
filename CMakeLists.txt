project(StaticMetaSingleton)

#set(CMAKE_CXX_VISIBILITY_PRESET hidden)

find_package(folly)

add_executable(main main.cc)
target_link_libraries(main shared Folly::folly)

add_library(shared SHARED shared.cc)
target_link_libraries(shared Folly::folly)
