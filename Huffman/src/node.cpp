#include <node.h>
#include "huffman_codes.h"

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

///////////////////////////////////////////////////////////////////////////////
bool Node::isLeaf()
{
    return label != NULL;
}

///////////////////////////////////////////////////////////////////////////////
void Node::createHuffmanCodeForLeafs( huffman_code& appended_code)
{
    appended_code.push_back(weight);
    if(isLeaf())
    {
        code = appended_code;
        HuffmanCodes::instance().codes->insert(std::pair<char,huffman_code>(label,code));
        return;
    }

    if(!left) left->createHuffmanCodeForLeafs(appended_code);
    if(!right) right->createHuffmanCodeForLeafs(appended_code);
}

}}
