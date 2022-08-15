cmake_minimum_required(VERSION 3.10)
project(web-graps-for-you)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

add_executable(grafy src/main.cpp src/Graph.hpp src/Vertex.hpp src/Edge.hpp src/BinarySearchTree.hpp src/Node.hpp)

enable_testing()

add_executable(test_set test/edge_tests.cc test/vertex_tests.cc test/graph_tests.cc test/binary_search_tree_tests.cc)


find_package(GTest)

target_link_libraries(
  test_set
  GTest::Main
)

include(GoogleTest)
gtest_discover_tests(test_set)