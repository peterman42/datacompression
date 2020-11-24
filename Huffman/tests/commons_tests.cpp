#include "gtest/gtest.h"
#include "commons.h"
#include "node.h"

using namespace DataCompression::Huffman;

TEST(Commons, countCharacters) {

    // Given
    std::string text = "This is a test text";
    std::list<Node> expected({ Node('T',1)
                             , Node('h',1)
                             , Node('i',2)
                             , Node('s',3)
                             , Node('\t' ,4)
                             , Node('a',1)
                             , Node('t',2)
                             , Node('e',2)
                             , Node('x',1)});

    // When
    auto actual = countCharacters(std::vector<char>(text.begin(), text.end()));

    // Then
    EXPECT_EQ(expected.size(), actual.size());
}

TEST(Commons, sortBufferAsc)
{
    // Given
    std::list<Node> given({ Node('T',1)
                             , Node('h',1)
                             , Node('i',2)
                             , Node('s',3)
                             , Node('\t' ,4)
                             , Node('a',1)
                             , Node('t',2)
                             , Node('e',2)
                             , Node('x',1)});
    std::list<Node> expected({ Node('T',1)
                             , Node('h',1)
                             , Node('a',1)
                             , Node('x',1)
                             , Node('i',2)
                             , Node('t',2)
                             , Node('e',2)
                             , Node('s',3)
                             , Node('\t' ,4)});

    // When
    sortBufferAsc(given);

    // Then
    EXPECT_EQ(given.size(), expected.size());
    for( int i =0 ; given.size(); ++i)
    {
            EXPECT_EQ(given.front().label, expected.front().label);
            EXPECT_EQ(given.front().value, expected.front().value);
            given.pop_front();
            expected.pop_front();
    }

}
