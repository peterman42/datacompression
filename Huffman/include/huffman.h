#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <list>
#include <string>
#include <btree.h>

namespace DataCompression { namespace Huffman {

struct count_character
{
    char character;
    uint32_t num;

    count_character(const char& _character, uint32_t _num)
        : character(_character)
        , num(_num)
    {}

    bool operator<(const count_character& c) const
    {
        return num < c.num;
    }
};

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
    std::list<count_character> countCharacters (const std::string& text);
    ///////////////////////////////////////////////////////////////////////////////
    void sortBuffer(std::list<count_character>&  buffer);

    ///////////////////////////////////////////////////////////////////////////////
    ~Huffman() = default;
    Huffman(const Huffman& T) = default;
    Huffman& operator=(const Huffman& T) = default;
    Huffman(Huffman&& T) = default;
    Huffman& operator=(Huffman&& T) = default;

};
}}
#endif // HUFFMAN_H
