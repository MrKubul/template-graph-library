cmake_minimum_required(VERSION 3.10)
project(mentoring-project)

set(CMAKE_CXX_STANDARD 17)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra --pedantic -std=c++17")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)


add_executable(grafy src/main.cpp src/graph/Graph.hpp src/graph/Vertex.hpp src/graph/Edge.hpp src/graph/BinarySearchTree.hpp src/graph/Node.hpp)
set_target_properties(grafy PROPERTIES LINKER_LANGUAGE CXX)
add_executable(test_set test/graph/edge_tests.cpp test/graph/vertex_tests.cpp test/graph/graph_tests.cpp test/graph/binary_search_tree_tests.cpp)

enable_testing()

find_package(GTest)

target_link_libraries(
  test_set
  GTest::Main
)

include(GoogleTest)
gtest_discover_tests(test_set)
