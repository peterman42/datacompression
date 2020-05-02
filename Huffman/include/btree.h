#ifndef BTREE_H
#define BREE_H
#include <memory>
#include <node.h>

namespace DataCompression { namespace Huffman {

class BTree
{
public:

    BTree();

    std::shared_ptr<Node> root;

    ///////////////////////////////////////////////////////////////////////////////
    void add(const Node& node);

    ///////////////////////////////////////////////////////////////////////////////
    void traverse();

    ///////////////////////////////////////////////////////////////////////////////
    ~BTree() = default;
    BTree(const BTree& T) = default;
    BTree& operator=(const BTree& T) = default;
    BTree(BTree&& T) = default;
    BTree& operator=(BTree&& T) = default;
};
} }
#endif
