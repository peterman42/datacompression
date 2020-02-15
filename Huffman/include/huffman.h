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
    ///////////////////////////////////////////////////////////////////////////////
    void encode(const std::string& text);
    ///////////////////////////////////////////////////////////////////////////////
    void decode(const std::string& text);
private:

    BTree binary_tree;
    std::map<char, huffman_code> codes;

    ///////////////////////////////////////////////////////////////////////////////
    std::list<Node> countCharacters (const std::string& text);
    ///////////////////////////////////////////////////////////////////////////////
    void sortBufferAsc(std::list<Node>& priority_queue);
    ///////////////////////////////////////////////////////////////////////////////
    void mergeNodesWithLessProbability(std::list<Node>& priority_queue);

    ///////////////////////////////////////////////////////////////////////////////
    ~Huffman() = default;
    Huffman(const Huffman& T) = default;
    Huffman& operator=(const Huffman& T) = default;
    Huffman(Huffman&& T) = default;
    Huffman& operator=(Huffman&& T) = default;

};
}}
#endif // HUFFMAN_H
