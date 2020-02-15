#ifndef NODE_H
#define NODE_H
#include <memory>
#include <bitset>

namespace DataCompression { namespace Huffman {

class Node
{
public:
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    char label;
    uint32_t value;
    std::bitset<1> weight;

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

    ~Node() = default;
    Node(const Node& T) = default;
    Node& operator=(const Node& T) = default;
    Node(Node&& T) = default;
    Node& operator=(Node&& T) = default;

};
} }
#endif
