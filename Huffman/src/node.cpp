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
void Node::createHuffmanCodes( huffman_code appended_code)
{
    appended_code.push_back(weight);
    if(isLeaf())
    {
        code = appended_code;
        HuffmanCodes::instance().codes->insert(std::pair<char,huffman_code>(label,code));
        return;
    }

    if(!left) trasmitCurrentCodeToInternalNode(left, appended_code);

    if(!right) trasmitCurrentCodeToInternalNode(right, appended_code);
}

///////////////////////////////////////////////////////////////////////////////
void Node::trasmitCurrentCodeToInternalNode(std::shared_ptr<Node> node, huffman_code& code)
{
    node->createHuffmanCodes(code);
}

///////////////////////////////////////////////////////////////////////////////
void Node::saveHuffmanCodeForLeaf(const huffman_code& huffman_code)
{
    code = huffman_code;
    HuffmanCodes::instance().codes->insert(std::pair<char,std::vector<bit>>(label,code));
}

}}
