#include <gtest/gtest.h>
#include "huffman.h"

using namespace DataCompression::Huffman;


TEST(Huffman, encode)
{
    // Given
    std::string text = "This is a test text.";
    Huffman huffman;

    // When
    huffman.encode(text);

    // Then
    EXPECT_TRUE(huffman.binary_tree.root);
}
