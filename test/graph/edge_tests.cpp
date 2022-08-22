#include <gtest/gtest.h>
#include <string>
#include "../../src/graph/Edge.hpp"


class EdgeTest : public ::testing::Test {
 protected:
  int srcPlaceHolder = 10;
  Edge<int> edgeInt_operator_first = Edge<int>(srcPlaceHolder, 1, 7312);
  Edge<int> edgeInt_operator_second = Edge<int>(srcPlaceHolder, 1, 789);
  Edge<int> edgeInt = Edge<int>(srcPlaceHolder, 1, 7312);
  Edge<float> edgeFloat = Edge<float>(srcPlaceHolder, 2, 4.2);
  Edge<char> edgeChar = Edge<char>(srcPlaceHolder, 3, 'a');
  Edge<std::string> edgeString = Edge<std::string>(srcPlaceHolder, 4, "testing_string");
  Edge<bool> edgeBool = Edge<bool>(srcPlaceHolder, 5, true);
};

TEST_F(EdgeTest, OperatorsTest) {
   EXPECT_TRUE(edgeInt_operator_first == edgeInt);
   EXPECT_TRUE(!(edgeInt == edgeInt_operator_second));
}

TEST_F(EdgeTest, GettersTest) {
  EXPECT_EQ(edgeInt.getDestinationID(), 1);
  EXPECT_EQ(edgeInt.getWeight(), 7312);

  EXPECT_EQ(edgeFloat.getDestinationID(), 2);
  EXPECT_EQ(edgeFloat.getWeight(),  4.2f);

  EXPECT_EQ(edgeChar.getDestinationID(), 3);
  EXPECT_EQ(edgeChar.getWeight(), 'a');

  EXPECT_EQ(edgeString.getDestinationID(), 4);
  EXPECT_EQ(edgeString.getWeight(), "testing_string");

  EXPECT_EQ(edgeBool.getDestinationID(),  5);
  EXPECT_EQ(edgeBool.getWeight(),  true);
}

TEST_F(EdgeTest, SettersTest) 
{ 
   edgeInt.setDestinationID(10);
   edgeInt.setWeight(16);
   EXPECT_EQ(edgeInt.getDestinationID(), 10);
   EXPECT_EQ(edgeInt.getWeight(), 16);

   edgeFloat.setWeight(1.99f);
   EXPECT_EQ(edgeFloat.getWeight(),  1.99f);

   edgeChar.setWeight('b');
   EXPECT_EQ(edgeChar.getWeight(), 'b');

   edgeString.setWeight("dusbfuadb37621731");
   EXPECT_EQ(edgeString.getWeight(), "dusbfuadb37621731");
   
   edgeBool.setWeight(false);
   EXPECT_EQ(edgeBool.getWeight(), false);
}

TEST_F(EdgeTest, VisitedToggling) 
{ 
   EXPECT_EQ(edgeInt.visitedStatus.get(), false);
   edgeInt.visitedStatus.setTrue();
   EXPECT_EQ(edgeInt.visitedStatus.get(), true);
   edgeInt.visitedStatus.setFalse();
   EXPECT_EQ(edgeInt.visitedStatus.get(), false);
}