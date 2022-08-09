#include <gtest/gtest.h>
#include <string>
#include "../src/Graph.hpp"

//test kazdego ecxeption

class GraphTest : public ::testing::Test {
 protected:
  Graph<int, int> test_graph_1 = Graph<int, int>();
  Graph<std::string, std::string> test_graph_2 = Graph<std::string, std::string>();
  Graph<float, float> test_graph_3 = Graph<float, float>();
};

TEST_F(GraphTest, CheckingVertexExistance)
{ 
   Vertex<int, int> test_vertex_1 = Vertex<int, int>(1, 18);
   Vertex<int, int > test_vertex_2 = Vertex<int, int>(2, 9);
   Vertex<int, int> test_vertex_3 = Vertex<int, int>(3, 33);

   test_graph_1.addVertex(test_vertex_1);
   test_graph_1.addVertex(test_vertex_2);
   test_graph_1.addVertex(test_vertex_3);

   EXPECT_EQ(test_graph_1.checkIfVertexExists(1), true );
   EXPECT_EQ(test_graph_1.checkIfVertexExists(2), true );
   EXPECT_EQ(test_graph_1.checkIfVertexExists(4), false );
   EXPECT_EQ(test_graph_1.checkIfVertexExists(3), true );
}

TEST_F(GraphTest, AddingVertexTest) {

  Vertex<int, int> test_vertex_1 = Vertex<int, int>(1, 18);
  Vertex<int, int > test_vertex_2 = Vertex<int, int>(2, 9);
  Vertex<int, int> test_vertex_3 = Vertex<int, int>(3, 33);

  test_graph_1.addVertex(test_vertex_1);
  test_graph_1.addVertex(test_vertex_2);
  test_graph_1.addVertex(test_vertex_3);

  EXPECT_THROW(test_graph_1.addVertex(test_vertex_2), std::invalid_argument);
  EXPECT_EQ((test_graph_1.getVertices()).size(), 3);
}

TEST_F(GraphTest, CheckingEdgeExistance) 
{ 
   Vertex<std::string, std::string> test_vertex_1 = Vertex<std::string, std::string>(1, "18");
   Vertex<std::string, std::string> test_vertex_2 = Vertex<std::string, std::string>(2, "9");
   Vertex<std::string, std::string> test_vertex_3 = Vertex<std::string, std::string>(3, "777");

   Edge<std::string> e = Edge<std::string>(10, 2, "testing");
   test_vertex_1.addToEdgeList(e);

   test_graph_2.addVertex(test_vertex_1);
   test_graph_2.addVertex(test_vertex_2);
   test_graph_2.addVertex(test_vertex_3);

   EXPECT_EQ(test_graph_2.checkIfEdgeExists(1,2), true );
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(2,1), false );
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(1,3), false );
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(3,2), false );
}

TEST_F(GraphTest, AddingEdgeAndWeightTest) 
{ 
   Vertex<std::string, std::string> test_vertex_1 = Vertex<std::string, std::string>(1, "18");
   Vertex<std::string, std::string> test_vertex_2 = Vertex<std::string, std::string>(2, "9");
   Vertex<std::string, std::string> test_vertex_3 = Vertex<std::string, std::string>(3, "777");

   test_graph_2.addVertex(test_vertex_1);
   test_graph_2.addVertex(test_vertex_2);
   test_graph_2.addVertex(test_vertex_3);

   test_graph_2.addEdge(test_vertex_1.getID(),test_vertex_2.getID(), "TEST_1");
   test_graph_2.addEdge(test_vertex_1.getID(),test_vertex_3.getID(), "TEST_2");

   EXPECT_EQ(test_graph_2.checkIfEdgeExists(1,2), true );
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(2,1), false );
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(1,3), true );
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(3,2), false );
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(3,1), false );
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(2,3), false );
   EXPECT_EQ(test_graph_2.getEdgeWeight(1,2), "TEST_1" );
   EXPECT_EQ(test_graph_2.getEdgeWeight(1,3), "TEST_2" );
}

TEST_F(GraphTest, UpdatingAndDeletingEdgeByID) 
{ 
   Vertex<std::string, std::string> test_vertex_1 = Vertex<std::string, std::string>(1, "18");
   Vertex<std::string, std::string> test_vertex_2 = Vertex<std::string, std::string>(2, "9");
   Vertex<std::string, std::string> test_vertex_3 = Vertex<std::string, std::string>(3, "777");

   test_graph_2.addVertex(test_vertex_1);
   test_graph_2.addVertex(test_vertex_2);
   test_graph_2.addVertex(test_vertex_3);

   test_graph_2.addEdge(1,2, "TEST_1");
   test_graph_2.addEdge(1,3, "TEST_2");

   test_graph_2.updateEdgeByID(1, 3, "zmiana_1");
   EXPECT_EQ(test_graph_2.getEdgeWeight(1,3), "zmiana_1" );
   test_graph_2.updateEdgeByID(1, 2, "zmiana_2");
   EXPECT_EQ(test_graph_2.getEdgeWeight(1,2), "zmiana_2" );

   EXPECT_THROW(test_graph_2.updateEdgeByID(test_vertex_2.getID(), test_vertex_1.getID(), "zmiana_2");
, std::invalid_argument);
   
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(test_vertex_1.getID(), test_vertex_2.getID()), true);
   test_graph_2.eraseEdgeByID(test_vertex_1.getID(), test_vertex_2.getID());
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(test_vertex_1.getID(), test_vertex_2.getID()), false);
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(test_vertex_1.getID(), test_vertex_3.getID()), true);
   test_graph_2.eraseEdgeByID(test_vertex_1.getID(), test_vertex_3.getID());
   EXPECT_EQ(test_graph_2.checkIfEdgeExists(test_vertex_1.getID(), test_vertex_3.getID()), false);
}

TEST_F(GraphTest, DeletingVertexByID) 
{ 
   Vertex<std::string, std::string> test_vertex_1 = Vertex<std::string, std::string>(1, "18");
   Vertex<std::string, std::string> test_vertex_2 = Vertex<std::string, std::string>(2, "9");
   Vertex<std::string, std::string> test_vertex_3 = Vertex<std::string, std::string>(3, "777");

   test_graph_2.addVertex(test_vertex_1);
   test_graph_2.addVertex(test_vertex_2);
   test_graph_2.addVertex(test_vertex_3);

   test_graph_2.deleteVertexByID(test_vertex_2.getID());
   test_graph_2.deleteVertexByID(test_vertex_3.getID());

   EXPECT_EQ(test_graph_2.checkIfVertexExists(1), true );
   EXPECT_EQ(test_graph_2.checkIfVertexExists(2), false );
   EXPECT_EQ(test_graph_2.checkIfVertexExists(3), false );
}

TEST_F(GraphTest, UpdatingVertexByID) 
{ 
   Vertex<std::string, std::string> test_vertex_1 = Vertex<std::string, std::string>(1, "18");
   Vertex<std::string, std::string> test_vertex_2 = Vertex<std::string, std::string>(2, "9");
   Vertex<std::string, std::string> test_vertex_3 = Vertex<std::string, std::string>(3, "777");

   test_graph_2.addVertex(test_vertex_1);
   test_graph_2.addVertex(test_vertex_2);
   test_graph_2.addVertex(test_vertex_3);

   test_graph_2.updateVertex(test_vertex_2.getID(), "testownik1");
   test_graph_2.updateVertex(test_vertex_3.getID(), "testownik2");

   EXPECT_EQ(test_graph_2.getVertexByID(1)->getValue(), "18" );
   EXPECT_EQ(test_graph_2.getVertexByID(2)->getValue(), "testownik1" );
   EXPECT_EQ(test_graph_2.getVertexByID(3)->getValue(), "testownik2" );
}



