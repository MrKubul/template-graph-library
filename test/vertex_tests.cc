#include <gtest/gtest.h>
#include <string>
#include "../src/Vertex.hpp"


class VertexTest : public ::testing::Test {
 protected:
  Vertex<int, int> vertexInt_first = Vertex<int, int>(1, 33);
  Vertex<int, int> vertexInt_second = Vertex<int, int>(776, 7312);
  Vertex<int, int> vertexInt = Vertex<int, int>(1, 7312);
  Vertex<float, float> vertexFloat = Vertex<float, float>(2, 4.2f);
  Vertex<char, char> vertexChar = Vertex<char, char>(3, 'a');
  Vertex<std::string, std::string> vertexString = Vertex<std::string, std::string>(4, "string-testing-purposes");
  Vertex<bool, bool> vertexBool = Vertex<bool, bool>(5, true);
};

TEST_F(VertexTest, OperatorsTest) {
   EXPECT_TRUE(vertexInt_first == vertexInt);
   EXPECT_TRUE(!(vertexInt == vertexInt_second));
}

TEST_F(VertexTest, GettersTest) {
  EXPECT_EQ(vertexInt.getID(), 1);
  EXPECT_EQ(vertexInt.getValue(), 7312);

  EXPECT_EQ(vertexFloat.getID(), 2);
  EXPECT_EQ(vertexFloat.getValue(),  4.2f);

  EXPECT_EQ(vertexChar.getID(), 3);
  EXPECT_EQ(vertexChar.getValue(), 'a');

  EXPECT_EQ(vertexString.getID(), 4);
  EXPECT_EQ(vertexString.getValue(), "string-testing-purposes");

  EXPECT_EQ(vertexBool.getID(),  5);
  EXPECT_EQ(vertexBool.getValue(),  true);
}

TEST_F(VertexTest, SettersTest) 
{ 
   vertexInt.setValue(16);
   EXPECT_EQ(vertexInt.getValue(), 16);

   vertexFloat.setValue(1.99f);
   EXPECT_EQ(vertexFloat.getValue(),  1.99f);

   vertexChar.setValue('b');
   EXPECT_EQ(vertexChar.getValue(), 'b');

   vertexString.setValue("testing_for_change");
   EXPECT_EQ(vertexString.getValue(), "testing_for_change");
   
   vertexBool.setValue(false);
   EXPECT_EQ(vertexBool.getValue(), false);
}