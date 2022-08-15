#include <gtest/gtest.h>
#include <string>
#include "../src/BinarySearchTree.hpp"

class BinarySearchTreeTest : public ::testing::Test {
 protected:
  BinarySearchTree<int> test_tree_1;
  BinarySearchTree<std::string> test_tree_2;
  BinarySearchTree<float> test_tree_3;
};

TEST_F(BinarySearchTreeTest, RetrievingRoot)
{ 
  EXPECT_EQ(test_tree_1.getRoot(), nullptr);
}

TEST_F(BinarySearchTreeTest, SettingRoot)
{ 
  Node<int>* newRoot = new Node<int>(350, 1);
  test_tree_1.setRoot(newRoot);
  EXPECT_EQ(test_tree_1.getRoot(), newRoot);
  test_tree_1.deleteTree();
}

TEST_F(BinarySearchTreeTest, SearchingTree) 
{
  Node<int>* newRoot = new Node<int>(350, 1);
  Node<int>* fakeNode = new Node<int>(450, 2);
  test_tree_1.setRoot(newRoot);
  EXPECT_TRUE(test_tree_1.search(350));
  EXPECT_TRUE(!(test_tree_1.search(450)));

  delete fakeNode;
  test_tree_1.deleteTree();
}

TEST_F(BinarySearchTreeTest, InsertingIntoTree) 
{ 
  test_tree_1.insert(33);
  test_tree_1.insert(44);
  test_tree_1.insert(20);

  EXPECT_TRUE(test_tree_1.search(33));
  EXPECT_TRUE(test_tree_1.search(44));
  EXPECT_TRUE(test_tree_1.search(20));
  EXPECT_FALSE(test_tree_1.search(66));

  test_tree_2.insert("first-node");
  test_tree_2.insert("second-node");
  test_tree_2.insert("third-node");

  EXPECT_TRUE(test_tree_2.search("first-node"));
  EXPECT_TRUE(test_tree_2.search("second-node"));
  EXPECT_TRUE(test_tree_2.search("third-node"));
  EXPECT_FALSE(test_tree_2.search("fourth-node"));
  test_tree_2.deleteTree();
  test_tree_1.deleteTree();
}

TEST_F(BinarySearchTreeTest, RemovingFormTree) 
{ 
  test_tree_2.insert("first-node");
  test_tree_2.insert("second-node");
  test_tree_2.insert("third-node");
  test_tree_2.insert("fourth-node");

  EXPECT_TRUE(test_tree_2.search("first-node"));
  EXPECT_TRUE(test_tree_2.search("second-node"));
  EXPECT_TRUE(test_tree_2.search("third-node"));
  EXPECT_TRUE(test_tree_2.search("fourth-node"));

  test_tree_2.remove("first-node");
  test_tree_2.remove("fourth-node");

  EXPECT_FALSE(test_tree_2.search("first-node"));
  EXPECT_TRUE(test_tree_2.search("second-node"));
  EXPECT_TRUE(test_tree_2.search("third-node"));
  EXPECT_FALSE(test_tree_2.search("fourth-node"));

  test_tree_2.deleteTree();
}

TEST_F(BinarySearchTreeTest, DeletingTree) 
{ 
  test_tree_2.insert("first-node");
  test_tree_2.insert("second-node");
  test_tree_2.insert("third-node");
  test_tree_2.insert("fourth-node");

  test_tree_2.deleteTree();

  EXPECT_EQ(test_tree_2.getSize(), 0);
}