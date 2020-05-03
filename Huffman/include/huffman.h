#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <list>
#include <string>
#include <btree.h>
#include "commons.h"
#include <map>

namespace DataCompression { namespace Huffman {

class Huffman
{
public:

    Huffman() = default;

    ///////////////////////////////////////////////////////////////////////////////
    void encode(const std::string& text);
    ///////////////////////////////////////////////////////////////////////////////
    void decode(const std::string& text);
    ///////////////////////////////////////////////////////////////////////////////
    huffman_code_map buildCodesMap();
    ///////////////////////////////////////////////////////////////////////////////
    ~Huffman() = default;
    Huffman(const Huffman& T) = default;
    Huffman& operator=(const Huffman& T) = default;
    Huffman(Huffman&& T) = default;
    Huffman& operator=(Huffman&& T) = default;

    BTree binary_tree;
    huffman_code_map_ptr codes;

private:

    ///////////////////////////////////////////////////////////////////////////////
    void mergeNodesWithLessProbability(std::list<Node>& priority_queue);
};
}}
#endif // HUFFMAN_H
