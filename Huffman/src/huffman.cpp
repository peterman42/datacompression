#include <huffman.h>
#include <algorithm>

namespace DataCompression { namespace Huffman {

///////////////////////////////////////////////////////////////////////////////
void Huffman::encode(const std::string& text)
{
}

///////////////////////////////////////////////////////////////////////////////
void Huffman::decode(const std::string& text)
{

}

///////////////////////////////////////////////////////////////////////////////
std::list<count_character> Huffman::countCharacters (const std::string& text)
{
    std::list <count_character> list_of_characters;
    try
    {
        for(const char& character : text)
        {

            auto exists_it = std::find_if(list_of_characters.begin()
                                      , list_of_characters.end()
                                      , [&character](const count_character& V)
            {
                if(V.character == character)
                    return true;
                else
                   return false;
            });

            if(exists_it != list_of_characters.end())
            {
                (exists_it->num)++;
            }
            else
            {
                list_of_characters.push_back(count_character(character, 0));
            }
        }
    }
    catch(...)
    {}

    return list_of_characters;
}

///////////////////////////////////////////////////////////////////////////////
void Huffman::sortBuffer(std::list<count_character>&  buffer)
{
    buffer.sort();
}
}}
