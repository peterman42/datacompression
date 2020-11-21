#include "gtest/gtest.h"
#include "huffman.h"

using namespace DataCompression::Huffman;

class HuffmanFixture : public ::testing::Test {
public :
    HuffmanFixture( ) {
        // initialization code here
    }

    void SetUp( ) {
        // code here will execute just before the test ensues
        expected_huffman_codes = {
            {' ', {0,0,0} },
            {'.', {0,1,0,1,0} },
            {'T', {0,1,1,1,0,0} },
            {'a', {0,1,0,1,1,0} },
            {'e', {0,1,0,0} },
            {'h', {0,1,1,1,0,1} },
            {'i', {0,1,1,1,1} },
            {'s', {0,1,1,0} },
            {'t', {0,0,1} },
            {'x', {0,1,0,1,1,1} }
        };

        given_text = "This is a test text.";
    }

    void TearDown( ) {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

    huffman_code_map expected_huffman_codes;
    std::string given_text;
};


TEST_F(HuffmanFixture, encode)
{
    // Given
    Huffman huffman;
    // When
    huffman.encode(given_text);

    // Then
    EXPECT_TRUE(huffman.binary_tree.root);
}

TEST_F(HuffmanFixture, buildCodesMap)
{
    // Given
    Huffman huffman;

    // When
    huffman.encode(given_text);
    const auto& actual_huffman_codes = huffman.buildCodesMap();

    // Then

    for(const auto& item : actual_huffman_codes)
    {
        auto code = expected_huffman_codes.at(item.first);
        ASSERT_EQ(item.second, code );
    }
}
