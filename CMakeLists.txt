#[[Project is developed under MIT License]]

cmake_minimum_required(VERSION 3.10)
project(mentoring-project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra --pedantic -std=c++2a")

option(STATIC_LIBS "Set static build" OFF)

set(GRAPH2D_LIB "src/graph2D_lib/Structure2D.hpp" "src/graph2D_lib/bst2D/Node2D.hpp" "src/graph2D_lib/bst2D/BinarySearchTree2D.hpp" "src/graph2D_lib/directed_graph2D/Vertex2D.hpp" "src/graph2D_lib/directed_graph2D/Graph2D.hpp" )
set(GRAPH_LIB "src/graph_lib/directed_graph/Graph.hpp" "src/graph_lib/directed_graph/Vertex.hpp" "src/graph_lib/directed_graph/Edge.hpp" "src/graph_lib/bst/BinarySearchTree.hpp" "src/graph_lib/bst/Node.hpp" "src/graph_lib/UnitVisitingOperations.hpp")
set(GUI "src/gui/gui.hpp" )
set(VISUALIZATION_FOR_GRAPHS "src/graph_lib/directed_graph/Graph.hpp" "src/graph_lib/directed_graph/Vertex.hpp" "src/graph_lib/directed_graph/Edge.hpp" "src/graph_lib/bst/BinarySearchTree.hpp" "src/graph_lib/bst/Node.hpp" "src/graph_lib/UnitVisitingOperations.hpp" )

set(GRAPH_TEST "test/graph/bst/binary_search_tree_tests.cpp" "test/graph/directed_graph/edge_tests.cpp" "test/graph/directed_graph/graph_tests.cpp" "test/graph/directed_graph/vertex_tests.cpp")
set(GRAPH2D_TEST "test/graph2D/structure2D_tests.cpp" "test/graph2D/bst/bst2D_tests.cpp" "test/graph2D/directed_graph/node2D_tests.cpp" "test/graph2D/directed_graph/graph2D_tests.cpp")
set(GUI_TEST "test/gui/gui_tests.cpp")
set(VISUALIZATION_TEST "test/visualization/visualization_tests.cpp")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
add_compile_options()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

include_directories(src)
add_executable(APP src/main.cpp ${GRAPH_LIB} ${GRAPH2D_LIB} ${GUI} ${VISUALIZATION_FOR_GRAPHS})

if(STATIC_LIBS)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

set(SFML_DIR "lib/SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS system audio window graphics REQUIRED)

target_link_libraries(APP sfml-graphics sfml-audio sfml-system -I mentoring_project/)
set_target_properties(APP PROPERTIES LINKER_LANGUAGE CXX)

include_directories(src)
add_executable(TEST_SUITE ${GRAPH_TEST} ${GRAPH2D_TEST})
target_link_libraries(TEST_SUITE sfml-graphics sfml-audio sfml-system )
set_target_properties(TEST_SUITE PROPERTIES LINKER_LANGUAGE CXX)


enable_testing()
find_package(GTest)

target_link_libraries(
  TEST_SUITE
  GTest::Main
)

include(GoogleTest)
gtest_discover_tests(TEST_SUITE)
