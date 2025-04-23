#include <gtest/gtest.h>
#include <iostream>

#include "../include/BST.h"


// Helper to test that BST structure holds expected elements
void assertBstContains(bst<int>& tree, const std::vector<int>& values) {
    for (int val : values) {
        EXPECT_TRUE(tree.find(val));
    }
}

TEST(BSTTest, InsertAndSize) {
    bst<int> tree;
    EXPECT_TRUE(tree.insert(10));
    EXPECT_TRUE(tree.insert(5));
    EXPECT_TRUE(tree.insert(15));
    EXPECT_FALSE(tree.insert(10)); // Duplicate

    EXPECT_EQ(tree.size(), 3);
}

TEST(BSTTest, FindWorks) {
    bst<int> tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);

    EXPECT_TRUE(tree.find(10));
    EXPECT_TRUE(tree.find(20));
    EXPECT_FALSE(tree.find(40));
}

TEST(BSTTest, FindMinMax) {
    bst<int> tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(35);

    EXPECT_EQ(tree.findMin(), 5);
    EXPECT_EQ(tree.findMax(), 35);
}

TEST(BSTTest, EraseLeafNode) {
    bst<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_TRUE(tree.erase(5));
    EXPECT_FALSE(tree.find(5));
    EXPECT_EQ(tree.size(), 2);
}

TEST(BSTTest, EraseNodeWithOneChild) {
    bst<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(1); // Left child of 5

    EXPECT_TRUE(tree.erase(5));
    EXPECT_FALSE(tree.find(5));
    EXPECT_TRUE(tree.find(1));
    EXPECT_EQ(tree.size(), 2);
}

TEST(BSTTest, EraseNodeWithTwoChildren) {
    bst<int> tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);

    EXPECT_TRUE(tree.erase(10));
    EXPECT_FALSE(tree.find(10));
    assertBstContains(tree, {5, 15, 20, 30});
    EXPECT_EQ(tree.size(), 4);
}

TEST(BSTTest, FindMinThrowsWhenEmpty) {
    bst<int> tree;
    EXPECT_THROW(tree.findMin(), std::logic_error);
}

TEST(BSTTest, FindMaxThrowsWhenEmpty) {
    bst<int> tree;
    EXPECT_THROW(tree.findMax(), std::logic_error);
}



int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
