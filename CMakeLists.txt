cmake_minimum_required(VERSION 3.13)

project(StaticMetaSingleton LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Uncomment this line to use an explicit tag for the SharedMutex used.
#add_compile_definitions(EXPLICIT_TAG)

find_package(folly)

add_executable(main main.cc)
target_link_libraries(main shared Folly::folly)

add_library(shared SHARED shared.cc)
target_link_libraries(shared Folly::folly)
set_target_properties(shared PROPERTIES CXX_VISIBILITY_PRESET hidden)
