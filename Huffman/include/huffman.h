#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <list>
#include <string>
#include <btree.h>

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

    ///////////////////////////////////////////////////////////////////////////////
    std::list<Node> countCharacters (const std::string& text);
    ///////////////////////////////////////////////////////////////////////////////
    void sortBuffer(std::list<Node>&  buffer);

    ///////////////////////////////////////////////////////////////////////////////
    ~Huffman() = default;
    Huffman(const Huffman& T) = default;
    Huffman& operator=(const Huffman& T) = default;
    Huffman(Huffman&& T) = default;
    Huffman& operator=(Huffman&& T) = default;

};
}}
#endif // HUFFMAN_H
