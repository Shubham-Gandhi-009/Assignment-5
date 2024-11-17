#ifndef MORSECODE_H
#define MORSECODE_H

#include <string>
#include <unordered_map>

/**
 * @brief Represents a node in the Morse code binary tree.
 */
struct TreeNode 
{
    char letter;    ///< The letter stored at this node (or '*' for the root).
    TreeNode* left; ///< Pointer to the left child.
    TreeNode* right; ///< Pointer to the right child.

    /**
     * @brief Constructor to initialize a tree node with a given letter.
     * @param c The letter to store in the node.
     */
    TreeNode(char c);    
};

/**
 * @brief The MorseCode class handles encoding and decoding of messages
 *        using Morse code, leveraging a binary tree structure.
 */
class MorseCode {
private:
    TreeNode* root;  ///< Root of the Morse code binary tree.
    std::unordered_map<char, std::string> morseMap; ///< Map to store Morse code for each letter.

    /**
     * @brief Builds the Morse code binary tree.
     * @return Pointer to the root of the Morse tree.
     */
    TreeNode* buildMorseTree();                

    /**
     * @brief Deletes the entire Morse code binary tree to free memory.
     * @param node Pointer to the current tree node.
     */
    void deleteTree(TreeNode* node);           

public:
    /**
     * @brief Constructs the MorseCode object and initializes the tree and encoding map.
     */
    MorseCode();                             

    /**
     * @brief Destructs the MorseCode object and frees the tree memory.
     */
    ~MorseCode();                              

    /**
     * @brief Encodes a plain text message into Morse code.
     * @param message The plain text message to encode.
     * @return The encoded Morse code message as a string.
     */
    std::string encodeMessage(const std::string& message);  

    /**
     * @brief Decodes a Morse code message back into plain text.
     * @param morseCode The Morse code message to decode.
     * @return The decoded plain text message as a string.
     */
    std::string decodeMessage(const std::string& morseCode);
};

#endif // MORSECODE_H
