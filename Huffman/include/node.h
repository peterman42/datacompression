#ifndef NODE_H
#define NODE_H
#include <memory>
#include <bitset>
#include "commons.h"

namespace DataCompression { namespace Huffman {

class Node
{
public:
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    char label;
    uint32_t value;
    bit weight;
    huffman_code code;

    ///////////////////////////////////////////////////////////////////////////////
    Node( std::shared_ptr<Node> _left
        , std::shared_ptr<Node> _right
        , char _label
        , uint32_t _value);

    ///////////////////////////////////////////////////////////////////////////////
    Node( std::shared_ptr<Node> _left
        , std::shared_ptr<Node> _right
        , uint32_t _value);

    ///////////////////////////////////////////////////////////////////////////////
    Node( char _label
        , uint32_t _value);

    ///////////////////////////////////////////////////////////////////////////////
    void traverse();

    ///////////////////////////////////////////////////////////////////////////////
    bool isLeaf();

    ///////////////////////////////////////////////////////////////////////////////
    void createHuffmanCodeForLeafs(huffman_code&);

    ~Node() = default;
    Node(const Node& T) = default;
    Node& operator=(const Node& T) = default;
    Node(Node&& T) = default;
    Node& operator=(Node&& T) = default;

};
} }
#endif
