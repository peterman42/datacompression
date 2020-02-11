#include <node.h>

namespace DataCompression { namespace Huffman {

///////////////////////////////////////////////////////////////////////////////
Node::Node( std::shared_ptr<Node> _right
		  , std::shared_ptr<Node> _left
          , char _label
          , uint32_t _value)
	: right(_right)
	, left(_left)
    , label(_label)
    , value(_value)
{}

///////////////////////////////////////////////////////////////////////////////
Node::Node( std::shared_ptr<Node> _right
          , std::shared_ptr<Node> _left
          , uint32_t _value)
    : right(_right)
    , left(_left)
    , value(_value)
{}

///////////////////////////////////////////////////////////////////////////////
Node::Node( char _label
          , uint32_t _value)
    : value(_value)
    , label(_label)
{}

}}
