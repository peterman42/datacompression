#include <node.h>

namespace DataCompression { namespace Huffman {

///////////////////////////////////////////////////////////////////////////////
Node::Node( std::shared_ptr<Node> _left
          , std::shared_ptr<Node> _right
          , char _label
          , uint32_t _value)
    : left(_left)
    , right(_right)
    , label(_label)
    , value(_value)
    , weight(0)
    , code()
{}

///////////////////////////////////////////////////////////////////////////////
Node::Node( std::shared_ptr<Node> _left
          , std::shared_ptr<Node> _right
          , uint32_t _value)
    : left(_left)
    , right(_right)
    , label(NULL)
    , value(_value)
    , weight(0)
    , code()
{}

///////////////////////////////////////////////////////////////////////////////
Node::Node( char _label
          , uint32_t _value)
    : left(nullptr)
    , right(nullptr)
    , label(_label)
    , value(_value)
    , weight(0)
    , code()
{}

///////////////////////////////////////////////////////////////////////////////
void Node::traverse()
{
    if(left != nullptr)
    {
        left->weight = 0;
        left->traverse();
    }

    if(right != nullptr)
    {
        right->weight = 1;
        right->traverse();
    }
}

}}
