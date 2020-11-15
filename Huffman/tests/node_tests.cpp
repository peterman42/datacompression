#include "gtest/gtest.h"
#include "node.h"

using namespace DataCompression::Huffman;

TEST(Node, isLeafReturnsTrue)
{
    // Given
    Node node('g', 55);

    // When
    auto actual = node.isLeaf();

    // Then
    EXPECT_TRUE(actual);
}

TEST(Node, isLeafReturnsFalse)
{
    // Given
    Node node(nullptr,nullptr, 55);

    // When
    auto actual = node.isLeaf();

    // Then
    EXPECT_FALSE(actual);
}
