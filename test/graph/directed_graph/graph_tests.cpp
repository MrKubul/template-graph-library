#include <gtest/gtest.h>
#include <string>
#include "graph_lib/directed_graph/Graph.hpp"

using namespace GTL;

class IntGraphTest : public ::testing::Test {
 protected:
  Graph<int, int> simple_int_graph = Graph<int, int>();
  Graph<int, int> complex_int_graph = Graph<int, int>();

  void SetUp() override
  {
      Vertex<int, int> int_vertex_1 = Vertex<int, int>(1, 1);
      Vertex<int, int > int_vertex_2 = Vertex<int, int>(2, 2);
      Vertex<int, int> int_vertex_3 = Vertex<int, int>(3, 3);
      Vertex<int, int> int_vertex_4 = Vertex<int, int>(4, 4);
      Vertex<int, int > int_vertex_5 = Vertex<int, int>(5, 5);
      Vertex<int, int> int_vertex_6 = Vertex<int, int>(6, 6);
      Vertex<int, int> int_vertex_7 = Vertex<int, int>(7, 7);
      Vertex<int, int > int_vertex_8 = Vertex<int, int>(8, 8);
      Vertex<int, int> int_vertex_9 = Vertex<int, int>(9, 9);
      Vertex<int, int > int_vertex_10 = Vertex<int, int>(10, 10);

      simple_int_graph.addVertex(int_vertex_1);
      simple_int_graph.addVertex(int_vertex_2);
      simple_int_graph.addVertex(int_vertex_3);
      simple_int_graph.addVertex(int_vertex_4);
      simple_int_graph.addVertex(int_vertex_5);

      simple_int_graph.addEdge(1,3,3);
      simple_int_graph.addEdge(2,1,6);
      simple_int_graph.addEdge(3,2,5);
      simple_int_graph.addEdge(3,4,7);
      simple_int_graph.addEdge(4,5,1);
      simple_int_graph.addEdge(2,4,4);
      simple_int_graph.addEdge(4,2,3);

      complex_int_graph.addVertex(int_vertex_1);
      complex_int_graph.addVertex(int_vertex_2);
      complex_int_graph.addVertex(int_vertex_3);
      complex_int_graph.addVertex(int_vertex_4);
      complex_int_graph.addVertex(int_vertex_5);
      complex_int_graph.addVertex(int_vertex_6);
      complex_int_graph.addVertex(int_vertex_7);
      complex_int_graph.addVertex(int_vertex_8);
      complex_int_graph.addVertex(int_vertex_9);
      complex_int_graph.addVertex(int_vertex_10);

      complex_int_graph.addEdge(1,2,10);
      complex_int_graph.addEdge(2,4,2);
      complex_int_graph.addEdge(2,5,6);
      complex_int_graph.addEdge(3,2,7);
      complex_int_graph.addEdge(3,5,6);
      complex_int_graph.addEdge(3,7,4);
      complex_int_graph.addEdge(4,1,5);
      complex_int_graph.addEdge(4,5,8);
      complex_int_graph.addEdge(4,8,5);
      complex_int_graph.addEdge(5,2,4);
      complex_int_graph.addEdge(5,6,3);
      complex_int_graph.addEdge(6,3,5);
      complex_int_graph.addEdge(6,7,7);
      complex_int_graph.addEdge(6,8,6);
      complex_int_graph.addEdge(7,3,3);
      complex_int_graph.addEdge(7,8,9);
      complex_int_graph.addEdge(8,4,4);
      complex_int_graph.addEdge(8,9,5);
      complex_int_graph.addEdge(9,10,3);
  }

  void TearDown() override
  {
      
  }
};

class StringGraphTest : public ::testing::Test {
 protected:
  Graph<std::string, std::string> simple_string_graph = Graph<std::string, std::string>();
  Graph<std::string, std::string> complex_string_graph = Graph<std::string, std::string>();

  void SetUp() override
  {
      Vertex<std::string, std::string> string_vertex_1 = Vertex<std::string, std::string>(1, "1");
      Vertex<std::string, std::string > string_vertex_2 = Vertex<std::string, std::string>(2, "2");
      Vertex<std::string, std::string> string_vertex_3 = Vertex<std::string, std::string>(3, "3");
      Vertex<std::string, std::string> string_vertex_4 = Vertex<std::string, std::string>(4, "4");
      Vertex<std::string, std::string > string_vertex_5 = Vertex<std::string, std::string>(5, "5");
      Vertex<std::string, std::string> string_vertex_6 = Vertex<std::string, std::string>(6, "6");
      Vertex<std::string, std::string> string_vertex_7 = Vertex<std::string, std::string>(7, "7");
      Vertex<std::string, std::string > string_vertex_8 = Vertex<std::string, std::string>(8, "8");
      Vertex<std::string, std::string> string_vertex_9 = Vertex<std::string, std::string>(9, "9");
      Vertex<std::string, std::string > string_vertex_10 = Vertex<std::string, std::string>(10, "10");


      simple_string_graph.addVertex(string_vertex_1);
      simple_string_graph.addVertex(string_vertex_2);
      simple_string_graph.addVertex(string_vertex_3);
      simple_string_graph.addVertex(string_vertex_4);
      simple_string_graph.addVertex(string_vertex_5);

      simple_string_graph.addEdge(1,3,"3");
      simple_string_graph.addEdge(2,1,"6");
      simple_string_graph.addEdge(3,2,"5");
      simple_string_graph.addEdge(3,4,"7");
      simple_string_graph.addEdge(4,5,"1");
      simple_string_graph.addEdge(2,4,"4");
      simple_string_graph.addEdge(4,2,"3");

      complex_string_graph.addVertex(string_vertex_1);
      complex_string_graph.addVertex(string_vertex_2);
      complex_string_graph.addVertex(string_vertex_3);
      complex_string_graph.addVertex(string_vertex_4);
      complex_string_graph.addVertex(string_vertex_5);
      complex_string_graph.addVertex(string_vertex_6);
      complex_string_graph.addVertex(string_vertex_7);
      complex_string_graph.addVertex(string_vertex_8);
      complex_string_graph.addVertex(string_vertex_9);
      complex_string_graph.addVertex(string_vertex_10);

      complex_string_graph.addEdge(1,2,"10");
      complex_string_graph.addEdge(2,4,"2");
      complex_string_graph.addEdge(2,5,"6");
      complex_string_graph.addEdge(3,2,"7");
      complex_string_graph.addEdge(3,5,"6");
      complex_string_graph.addEdge(3,7,"4");
      complex_string_graph.addEdge(4,1,"5");
      complex_string_graph.addEdge(4,5,"8");
      complex_string_graph.addEdge(4,8,"5");
      complex_string_graph.addEdge(5,2,"4");
      complex_string_graph.addEdge(5,6,"3");
      complex_string_graph.addEdge(6,3,"5");
      complex_string_graph.addEdge(6,7,"7");
      complex_string_graph.addEdge(6,8,"6");
      complex_string_graph.addEdge(7,3,"3");
      complex_string_graph.addEdge(7,8,"9");
      complex_string_graph.addEdge(8,4,"4");
      complex_string_graph.addEdge(8,9,"5");
      complex_string_graph.addEdge(9,10,"3");
  }

  void TearDown() override
  {
   
  }
};

class FloatGraphTest : public ::testing::Test {
 protected:
  Graph<float, float> simple_float_graph = Graph<float, float>();
  Graph<float, float> complex_float_graph = Graph<float, float>();

  void SetUp() override
  {
      Vertex<float, float> float_vertex_1 = Vertex<float, float>(1, 1.0f);
      Vertex<float, float > float_vertex_2 = Vertex<float, float>(2, 2.0f);
      Vertex<float, float> float_vertex_3 = Vertex<float, float>(3, 3.0f);
      Vertex<float, float> float_vertex_4 = Vertex<float, float>(4, 4.0f);
      Vertex<float, float > float_vertex_5 = Vertex<float, float>(5, 5.0f);
      Vertex<float, float> float_vertex_6 = Vertex<float, float>(6, 6.0f);
      Vertex<float, float> float_vertex_7 = Vertex<float, float>(7, 7.0f);
      Vertex<float, float > float_vertex_8 = Vertex<float, float>(8, 8.0f);
      Vertex<float, float> float_vertex_9 = Vertex<float, float>(9, 9.0f);
      Vertex<float, float > float_vertex_10 = Vertex<float, float>(10, 10.0f);

      simple_float_graph.addVertex(float_vertex_1);
      simple_float_graph.addVertex(float_vertex_2);
      simple_float_graph.addVertex(float_vertex_3);
      simple_float_graph.addVertex(float_vertex_4);
      simple_float_graph.addVertex(float_vertex_5);

      simple_float_graph.addEdge(1,3,3.0f);
      simple_float_graph.addEdge(2,1,6.0f);
      simple_float_graph.addEdge(3,2,5.0f);
      simple_float_graph.addEdge(3,4,7.0f);
      simple_float_graph.addEdge(4,5,1.0f);
      simple_float_graph.addEdge(2,4,4.0f);
      simple_float_graph.addEdge(4,2,3.0f);

      complex_float_graph.addVertex(float_vertex_1);
      complex_float_graph.addVertex(float_vertex_2);
      complex_float_graph.addVertex(float_vertex_3);
      complex_float_graph.addVertex(float_vertex_4);
      complex_float_graph.addVertex(float_vertex_5);
      complex_float_graph.addVertex(float_vertex_6);
      complex_float_graph.addVertex(float_vertex_7);
      complex_float_graph.addVertex(float_vertex_8);
      complex_float_graph.addVertex(float_vertex_9);
      complex_float_graph.addVertex(float_vertex_10);

      complex_float_graph.addEdge(1,2,10.0f);
      complex_float_graph.addEdge(2,4,2.0f);
      complex_float_graph.addEdge(2,5,6.0f);
      complex_float_graph.addEdge(3,2,7.0f);
      complex_float_graph.addEdge(3,5,6.0f);
      complex_float_graph.addEdge(3,7,4.0f);
      complex_float_graph.addEdge(4,1,5.0f);
      complex_float_graph.addEdge(4,5,8.0f);
      complex_float_graph.addEdge(4,8,5.0f);
      complex_float_graph.addEdge(5,2,4.0f);
      complex_float_graph.addEdge(5,6,3.0f);
      complex_float_graph.addEdge(6,3,5.0f);
      complex_float_graph.addEdge(6,7,7.0f);
      complex_float_graph.addEdge(6,8,6.0f);
      complex_float_graph.addEdge(7,3,3.0f);
      complex_float_graph.addEdge(7,8,9.0f);
      complex_float_graph.addEdge(8,4,4.0f);
      complex_float_graph.addEdge(8,9,5.0f);
      complex_float_graph.addEdge(9,10,3.0f);
  }

  void TearDown() override
  {
   
  }
};

TEST_F(IntGraphTest, CheckingVertexExistance)
{ 
   EXPECT_EQ(simple_int_graph.checkIfVertexExists(1), true );
   EXPECT_EQ(simple_int_graph.checkIfVertexExists(3), true );
   EXPECT_EQ(simple_int_graph.checkIfVertexExists(5), true );
   EXPECT_EQ(simple_int_graph.checkIfVertexExists(6), false );
   EXPECT_EQ(simple_int_graph.checkIfVertexExists(45), false );
}

TEST_F(IntGraphTest, AddingVertexTest) {

  Vertex<int, int> new_vertex = Vertex<int, int>(6, 6);

  simple_int_graph.addVertex(new_vertex);

  EXPECT_THROW(simple_int_graph.addVertex(new_vertex), std::invalid_argument);
  EXPECT_EQ((simple_int_graph.getVertices()).size(), 6);
}

TEST_F(StringGraphTest, CheckingEdgeExistance) 
{ 
   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(1,3), true );
   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(4,5), true );
   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(3,5), false );
   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(4,1), false );
}

TEST_F(StringGraphTest, AddingEdgeAndWeightTest) 
{ 
   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(1,4), false );
   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(5,3), false );

   simple_string_graph.addEdge(1,4, "TEST_1");
   simple_string_graph.addEdge(5,3, "TEST_2");

   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(1,4), true );
   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(5,3), true );
   EXPECT_EQ(simple_string_graph.getEdgeWeight(1,4), "TEST_1" );
   EXPECT_EQ(simple_string_graph.getEdgeWeight(5,3), "TEST_2" );
   EXPECT_THROW(simple_string_graph.getEdgeWeight(5,99);, std::invalid_argument);


   EXPECT_THROW(simple_string_graph.addEdge(1,4, "AnotherEdgeHere");, std::invalid_argument);
   EXPECT_THROW(simple_string_graph.addEdge(1,10, "AnotherEdgeHere");, std::invalid_argument);
}

TEST_F(StringGraphTest, UpdatingAndDeletingEdgeByID) 
{ 
   simple_string_graph.updateEdgeByID(1, 3, "zmiana_1");
   EXPECT_EQ(simple_string_graph.getEdgeWeight(1,3), "zmiana_1" );
   simple_string_graph.updateEdgeByID(2,1, "zmiana_2");
   EXPECT_EQ(simple_string_graph.getEdgeWeight(2,1), "zmiana_2" );

   EXPECT_THROW(simple_string_graph.updateEdgeByID(1,2, "zmiana_2");
   , std::invalid_argument);
   
   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(4,5), true);
   simple_string_graph.eraseEdgeByID(4,5);
   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(4,5), false);

   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(2,1), true);
   simple_string_graph.eraseEdgeByID(2,1);
   EXPECT_EQ(simple_string_graph.checkIfEdgeExists(2,1), false);

   EXPECT_THROW(simple_string_graph.eraseEdgeByID(2,99);, std::invalid_argument);
}

TEST_F(FloatGraphTest, DeletingVertexAndItsEdgesTest) 
{ 
   EXPECT_EQ(simple_float_graph.checkIfVertexExists(5), true );
   EXPECT_EQ(simple_float_graph.checkIfEdgeExists(4,5), true);

   simple_float_graph.deleteVertexByID(5);

   EXPECT_EQ(simple_float_graph.checkIfVertexExists(5), false );
   EXPECT_EQ(simple_float_graph.checkIfEdgeExists(4,5), false);

   EXPECT_EQ(simple_float_graph.checkIfVertexExists(1), true );
   EXPECT_EQ(simple_float_graph.checkIfEdgeExists(1,3), true);
   EXPECT_EQ(simple_float_graph.checkIfEdgeExists(2,1), true);

   simple_float_graph.deleteVertexByID(1);

   EXPECT_EQ(simple_float_graph.checkIfVertexExists(1), false );
   EXPECT_EQ(simple_float_graph.checkIfEdgeExists(1,3), false);
   EXPECT_EQ(simple_float_graph.checkIfEdgeExists(2,1), false);

   EXPECT_THROW(simple_float_graph.deleteVertexByID(99);, std::invalid_argument);
}

TEST_F(StringGraphTest, UpdatingVertexByID) 
{ 
   EXPECT_EQ(simple_string_graph.getVertexByID(1)->getValue(), "1" );
   EXPECT_EQ(simple_string_graph.getVertexByID(4)->getValue(), "4" );

   simple_string_graph.updateVertex(1, "changedValue1");
   simple_string_graph.updateVertex(4, "changedValue2");

   EXPECT_EQ(simple_string_graph.getVertexByID(1)->getValue(), "changedValue1" );
   EXPECT_EQ(simple_string_graph.getVertexByID(4)->getValue(), "changedValue2" );

   EXPECT_THROW(simple_string_graph.updateVertex(99, "except");, std::invalid_argument);
}


TEST_F(FloatGraphTest, DepthFirstSearchTest) 
{ 
   Vertex<float, float>* vToSearch1 = simple_float_graph.getVertexByID(1);
   Vertex<float, float>* vToSearch2 = simple_float_graph.getVertexByID(2);
   Vertex<float, float>* vToSearch4 = simple_float_graph.getVertexByID(4);
   Vertex<float, float>* vToSearch5 = simple_float_graph.getVertexByID(5);
   

   EXPECT_TRUE(simple_float_graph.depthFirstSearch(vToSearch1, vToSearch5->getValue()));
   EXPECT_TRUE(simple_float_graph.depthFirstSearch(vToSearch1, vToSearch2->getValue()));
   EXPECT_TRUE(simple_float_graph.depthFirstSearch(vToSearch2, vToSearch4->getValue()));
   EXPECT_TRUE(simple_float_graph.depthFirstSearch(vToSearch2, vToSearch1->getValue()));
   
   
   EXPECT_FALSE(simple_float_graph.depthFirstSearch(vToSearch5, vToSearch4->getValue()));
   EXPECT_FALSE(simple_float_graph.depthFirstSearch(vToSearch5, vToSearch1->getValue()));
   EXPECT_FALSE(simple_float_graph.depthFirstSearch(vToSearch5, vToSearch2->getValue()));

   vToSearch1 = complex_float_graph.getVertexByID(1);
   vToSearch2 = complex_float_graph.getVertexByID(2);
   Vertex<float, float>* vToSearch3 = complex_float_graph.getVertexByID(3);
   vToSearch4 = complex_float_graph.getVertexByID(4);
   vToSearch5 = complex_float_graph.getVertexByID(5);
   Vertex<float, float>* vToSearch9 = complex_float_graph.getVertexByID(9);
   Vertex<float, float>* vToSearch10 = complex_float_graph.getVertexByID(10);

   EXPECT_TRUE(complex_float_graph.depthFirstSearch(vToSearch1, vToSearch5->getValue()));
   EXPECT_TRUE(complex_float_graph.depthFirstSearch(vToSearch1, vToSearch2->getValue()));
   EXPECT_TRUE(complex_float_graph.depthFirstSearch(vToSearch2, vToSearch4->getValue()));
   EXPECT_TRUE(complex_float_graph.depthFirstSearch(vToSearch2, vToSearch1->getValue()));
   
   EXPECT_FALSE(simple_float_graph.depthFirstSearch(vToSearch9, vToSearch3->getValue()));
   EXPECT_FALSE(simple_float_graph.depthFirstSearch(vToSearch10, vToSearch1->getValue()));
}

TEST_F(FloatGraphTest, BreadthFirstSearchTest) 
{ 
   Vertex<float, float>* vToSearch1 = simple_float_graph.getVertexByID(1);
   Vertex<float, float>* vToSearch2 = simple_float_graph.getVertexByID(2);
   Vertex<float, float>* vToSearch4 = simple_float_graph.getVertexByID(4);
   Vertex<float, float>* vToSearch5 = simple_float_graph.getVertexByID(5);
   

   EXPECT_TRUE(simple_float_graph.breadthFirstSearch(vToSearch1, vToSearch5->getValue()));
   EXPECT_TRUE(simple_float_graph.breadthFirstSearch(vToSearch1, vToSearch2->getValue()));
   EXPECT_TRUE(simple_float_graph.breadthFirstSearch(vToSearch2, vToSearch4->getValue()));
   EXPECT_TRUE(simple_float_graph.breadthFirstSearch(vToSearch2, vToSearch1->getValue()));
   
   
   EXPECT_FALSE(simple_float_graph.breadthFirstSearch(vToSearch5, vToSearch4->getValue()));
   EXPECT_FALSE(simple_float_graph.breadthFirstSearch(vToSearch5, vToSearch1->getValue()));
   EXPECT_FALSE(simple_float_graph.breadthFirstSearch(vToSearch5, vToSearch2->getValue()));

   vToSearch1 = complex_float_graph.getVertexByID(1);
   vToSearch2 = complex_float_graph.getVertexByID(2);
   Vertex<float, float>* vToSearch3 = complex_float_graph.getVertexByID(3);
   vToSearch4 = complex_float_graph.getVertexByID(4);
   vToSearch5 = complex_float_graph.getVertexByID(5);
   Vertex<float, float>* vToSearch9 = complex_float_graph.getVertexByID(9);
   Vertex<float, float>* vToSearch10 = complex_float_graph.getVertexByID(10);

   EXPECT_TRUE(complex_float_graph.breadthFirstSearch(vToSearch1, vToSearch9->getValue()));
   EXPECT_TRUE(complex_float_graph.breadthFirstSearch(vToSearch1, vToSearch2->getValue()));
   EXPECT_TRUE(complex_float_graph.breadthFirstSearch(vToSearch2, vToSearch4->getValue()));
   EXPECT_TRUE(complex_float_graph.breadthFirstSearch(vToSearch2, vToSearch1->getValue()));
   
   EXPECT_FALSE(complex_float_graph.breadthFirstSearch(vToSearch9, vToSearch3->getValue()));
   EXPECT_FALSE(complex_float_graph.breadthFirstSearch(vToSearch10, vToSearch1->getValue()));
}

TEST_F(IntGraphTest, DijktraAlgorithmTest) 
{
   Vertex<int, int>* vToSearch1 = simple_int_graph.getVertexByID(1);
   Vertex<int, int>* vToSearch2 = simple_int_graph.getVertexByID(2);
   Vertex<int, int>* vToSearch4 = simple_int_graph.getVertexByID(4);
   Vertex<int, int>* vToSearch5 = simple_int_graph.getVertexByID(5); 

   EXPECT_EQ(simple_int_graph.getShortestPath(vToSearch1, vToSearch5), 11);
   EXPECT_EQ(simple_int_graph.getShortestPath(vToSearch1, vToSearch2), 8);
   EXPECT_EQ(simple_int_graph.getShortestPath(vToSearch2, vToSearch4), 4);
   EXPECT_EQ(simple_int_graph.getShortestPath(vToSearch2, vToSearch1), 6);
   
   EXPECT_EQ(simple_int_graph.getShortestPath(vToSearch5, vToSearch4), -1);
   EXPECT_EQ(simple_int_graph.getShortestPath(vToSearch5, vToSearch1), -1);
   EXPECT_EQ(simple_int_graph.getShortestPath(vToSearch5, vToSearch2), -1);

   vToSearch1 = complex_int_graph.getVertexByID(1);
   vToSearch4 = complex_int_graph.getVertexByID(4);
   Vertex<int, int>* vToSearch9 = complex_int_graph.getVertexByID(9);
   Vertex<int, int>* vToSearch7 = complex_int_graph.getVertexByID(7);

   EXPECT_EQ(complex_int_graph.getShortestPath(vToSearch1, vToSearch9), 22);
   EXPECT_EQ(complex_int_graph.getShortestPath(vToSearch1, vToSearch7), 26);
   EXPECT_EQ(complex_int_graph.getShortestPath(vToSearch7, vToSearch4), 13);
   EXPECT_EQ(complex_int_graph.getShortestPath(vToSearch4, vToSearch7), 18);
   
   
   EXPECT_EQ(complex_int_graph.getShortestPath(vToSearch9, vToSearch1), -1);
   EXPECT_EQ(complex_int_graph.getShortestPath(vToSearch9, vToSearch4), -1);
   EXPECT_EQ(complex_int_graph.getShortestPath(vToSearch9, vToSearch7), -1);
   
}




