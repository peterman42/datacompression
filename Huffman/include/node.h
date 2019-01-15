#ifndef NODE_H
#define NODE_H
#include <memory>

namespace DataCompression { namespace Huffman {

class Node
{
    std::shared_ptr<Node> right;
    std::shared_ptr<Node> left;
    uint32_t value;

    ///////////////////////////////////////////////////////////////////////////////
	Node( std::shared_ptr<Node> _right
		, std::shared_ptr<Node> _left
		, uint32_t _value);
    ~Node() = default;
    Node(const Node& T) = default;
    Node& operator=(const Node& T) = default;
    Node(Node&& T) = default;
    Node& operator=(Node&& T) = default;

};
} }
#endif
