#include <btree.h>

namespace DataCompression { namespace Huffman {

BTree::BTree()
    : root(nullptr)
{}

///////////////////////////////////////////////////////////////////////////////
void BTree::add(const Node& node)
{
    if(!root) root = std::make_shared<Node>(node);
}

///////////////////////////////////////////////////////////////////////////////
void BTree::traverse()
{
    root->traverse();
}

}}
