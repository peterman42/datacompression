#ifndef BTREE_H
#define BREE_H
#include <memory>
#include <node.h>

namespace DataCompression { namespace Huffman {

class Btree
{
public:
    std::shared_ptr<Node> root;

    ///////////////////////////////////////////////////////////////////////////////
    ~Btree() = default;
    Btree(const Btree& T) = default;
    Btree& operator=(const Btree& T) = default;
    Btree(Btree&& T) = default;
    Btree& operator=(Btree&& T) = default;
};
} }
#endif
