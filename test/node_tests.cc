#include <gtest/gtest.h>
#include <string>
#include "../src/Node.hpp"

class NodeTest : public ::testing::Test {
 protected:
  Node<int> test_node_1 = Node<int>(123, 1);
  Node<std::string> test_node_2 = Node<std::string>("testing-string", 2);
  Node<float> test_node_3 = Node<float>(3.1415f, 3);
};

TEST_F(NodeTest, ValueGetter)
{ 
  EXPECT_EQ(test_node_1.getValue(), 123);
  EXPECT_EQ(test_node_2.getValue(), "testing-string");
  EXPECT_EQ(test_node_3.getValue(), 3.1415f);
}

TEST_F(NodeTest, ValueSetter) 
{
  test_node_1.setValue(456789);
  test_node_2.setValue("changed-string");
  test_node_3.setValue(2.713f);

  EXPECT_EQ(test_node_1.getValue(), 456789);
  EXPECT_EQ(test_node_2.getValue(), "changed-string");
  EXPECT_EQ(test_node_3.getValue(), 2.713f);
}