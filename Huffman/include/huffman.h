#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <list>
#include <vector>
#include <string>
#include <btree.h>
#include "commons.h"

namespace DataCompression { namespace Huffman {

class Huffman
{
public:

    ///////////////////////////////////////////////////////////////////////////////
    void encode(const std::vector<char>& text);
    ///////////////////////////////////////////////////////////////////////////////
    void decode(const std::vector<char>& text);
    ///////////////////////////////////////////////////////////////////////////////
    const huffman_code_map& buildCodesMap();
    ///////////////////////////////////////////////////////////////////////////////
    void printPriorityQueue();
    ///////////////////////////////////////////////////////////////////////////////
    void printHuffmanCodes(const huffman_code_map& codes);

    Huffman() = default;
    ~Huffman() = default;
    Huffman(const Huffman& T) = default;
    Huffman& operator=(const Huffman& T) = default;
    Huffman(Huffman&& T) = default;
    Huffman& operator=(Huffman&& T) = default;

    BTree binary_tree;
    std::list<Node> priority_queue;

private:

    ///////////////////////////////////////////////////////////////////////////////
    void mergeNodesWithLessProbability(std::list<Node>& priority_queue);

    ///////////////////////////////////////////////////////////////////////////////
    std::string toString(const huffman_code& code);

    ///////////////////////////////////////////////////////////////////////////////
    void clonePriorityQueue(std::list<Node>& clone);
};
}}
#endif // HUFFMAN_H
