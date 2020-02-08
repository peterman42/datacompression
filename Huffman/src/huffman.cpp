#include <huffman.h>
#include <algorithm>
#include "exceptions/priority_queue_exception.h"

namespace DataCompression { namespace Huffman {

///////////////////////////////////////////////////////////////////////////////
void Huffman::encode(const std::string& text)
{

    auto priority_queue = countCharacters(text);
    sortBufferAsc(priority_queue);

    // Merge the nodes into the priority queue.
    while(priority_queue.size() != 1)
    {
        mergeNodesWithLessProbabilities(priority_queue);
        sortBufferAsc(priority_queue);
    }

    if(priority_queue.size() != 1)
        throw PriorityQueueException("The priority queue should contain one node.");

    binary_tree.add(priority_queue.front());

}

///////////////////////////////////////////////////////////////////////////////
void Huffman::decode(const std::string& text)
{

}

///////////////////////////////////////////////////////////////////////////////
std::list<Node> Huffman::countCharacters (const std::string& text)
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
            {
                (exists_it->value)++;
            }
            else
            {
                list_of_characters.push_back(Node(character, 0));
            }
        }
    }
    catch(...)
    {}

    return list_of_characters;
}

///////////////////////////////////////////////////////////////////////////////
void Huffman::sortBufferAsc(std::list<Node>& priority_queue)
{
    priority_queue.sort([](const Node& nodeA, const Node& nodeB)
    {
        return nodeA.value < nodeB.value;
    });
}

///////////////////////////////////////////////////////////////////////////////
void Huffman::mergeNodesWithLessProbabilities(std::list<Node>& priority_queue)
{

}

}}
