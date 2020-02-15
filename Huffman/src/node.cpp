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
{}

///////////////////////////////////////////////////////////////////////////////
Node::Node( std::shared_ptr<Node> _left
          , std::shared_ptr<Node> _right
          , uint32_t _value)
    : left(_left)
    , right(_right)
    , value(_value)
{}

///////////////////////////////////////////////////////////////////////////////
Node::Node( char _label
          , uint32_t _value)
    : left(nullptr)
    , right(nullptr)
    , label(_label)
    , value(_value)
{}

}}
