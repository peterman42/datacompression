#include "gtest/gtest.h"
#include "commons.h"
#include "node.h"

namespace DataCompression { namespace Huffman {



TEST(Commons, countCharacters) {

    // Given
    std::string text = "This is a test text";
    std::list<Node> expected({ Node('T',1)
                             , Node('h',1)
                             , Node('i',2)
                             , Node('s',3)
                             , Node("''" ,4)
                             , Node('a',1)
                             , Node('t',2)
                             , Node('e',2)
                             , Node('x',1)});

    // When
    auto actual = countCharacters(text);

    // Then
    EXPECT_EQ(expected.size(), actual.size());
}

}}
