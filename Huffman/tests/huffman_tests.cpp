#include "gtest/gtest.h"
#include "huffman.h"
#include <fstream>
#include <vector>

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
        given_filename = "/home/petros/Documents/test_video.mp4";

    }

    void TearDown( ) {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

    huffman_code_map expected_huffman_codes;
    std::string given_text;
    std::string given_filename;
};


TEST_F(HuffmanFixture, encode)
{
    // Given
    Huffman huffman;
    // When
    huffman.encode(std::vector<char>(given_text.begin(), given_text.end()));

    // Then
    EXPECT_TRUE(huffman.binary_tree.root);
}

TEST_F(HuffmanFixture, buildCodesMap)
{
    // Given
    Huffman huffman;

    // When
    huffman.encode(std::vector<char>(given_text.begin(), given_text.end()));
    const auto& actual_huffman_codes = huffman.buildCodesMap();
    huffman.printHuffmanCodes(actual_huffman_codes);

    // Then
    for(const auto& item : actual_huffman_codes)
    {
        auto code = expected_huffman_codes.at(item.first);
        ASSERT_EQ(item.second, code );
    }
}

TEST_F(HuffmanFixture, DISABLE_compressBinary)
{
    // Given
    Huffman huffman;
    std::vector<char> file_bytes;
    load_file(given_filename, file_bytes);

    // When
    huffman.encode(file_bytes);
    const auto& actual_huffman_codes = huffman.buildCodesMap();
    huffman.printPriorityQueue();

    // Then
    huffman.printHuffmanCodes(actual_huffman_codes);

}
