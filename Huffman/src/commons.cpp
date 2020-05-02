#include "commons.h"
#include <algorithm>
#include "node.h"

namespace DataCompression { namespace Huffman {

std::list<Node> countCharacters (const std::string& text)
{
    std::list <Node> list_of_characters;
    try
    {
        for(const char& character : text)
        {

            auto exists_it = std::find_if(list_of_characters.begin()
                                      , list_of_characters.end()
                                      , [&character](const Node& V)
            {
                if(V.label == character)
                    return true;
                else
                   return false;
            });

            if(exists_it != list_of_characters.end())
                (exists_it->value)++;
            else
                list_of_characters.push_back(Node(character, 1));
        }
    }
    catch(...)
    {}

    return list_of_characters;
}

///////////////////////////////////////////////////////////////////////////////
void sortBufferAsc(std::list<Node>& priority_queue)
{
    priority_queue.sort([](const Node& nodeA, const Node& nodeB)
    {
        return nodeA.value < nodeB.value;
    });
}

}}
