#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <list>
#include <string>

namespace DataCompression { namespace Huffman {

using count_character = std::pair<char, uint32_t>;

class Huffman
{
public:
    void encode();
    voide decode();
private:
    std::list<count_character> countCharacters (const std::string& text);

    ///////////////////////////////////////////////////////////////////////////////
    ~Huffman() = default;
    Huffman(const Huffman& T) = default;
    Huffman& operator=(const Huffman& T) = default;
    Huffman(Huffman&& T) = default;
    Huffman& operator=(Huffman&& T) = default;

};
}}
#endif // HUFFMAN_H
