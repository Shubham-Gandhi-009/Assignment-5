#include "MorseCode.h"
#include <sstream>
#include <cctype>
#include <iostream>

// TreeNode constructor
TreeNode::TreeNode(char c) : letter(c), left(nullptr), right(nullptr) {}

// MorseCode constructor
MorseCode::MorseCode() {
    root = buildMorseTree();
    morseMap = {
        {'a', ".- "},   {'b', "-... "}, {'c', "-.-. "}, {'d', "-.. "},
        {'e', ". "},    {'f', "..-. "}, {'g', "--. "},  {'h', ".... "},
        {'i', ".. "},   {'j', ".--- "}, {'k', "-.- "},  {'l', ".-.. "},
        {'m', "-- "},   {'n', "-. "},   {'o', "--- "},  {'p', ".--. "},
        {'q', "--.- "}, {'r', ".-. "},  {'s', "... "},  {'t', "- "},
        {'u', "..- "},  {'v', "...- "}, {'w', ".-- "},  {'x', "-..- "},
        {'y', "-.-- "}, {'z', "--.. "}, {' ', "   "}
    };
}

// MorseCode destructor
MorseCode::~MorseCode() 
{
    deleteTree(root);
}

// Implementation for delete tree nodes
void MorseCode::deleteTree(TreeNode* node) 
{
    if (node) 
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// Initializing of a Morse Tree 
TreeNode* MorseCode::buildMorseTree() 
{
    TreeNode* root = new TreeNode('*');

    root->left = new TreeNode('e');
    root->right = new TreeNode('t');

    root->left->left = new TreeNode('i');
    root->left->right = new TreeNode('a');
    root->right->left = new TreeNode('n');
    root->right->right = new TreeNode('m');

    root->left->left->left = new TreeNode('s');
    root->left->left->right = new TreeNode('u');
    root->left->right->left = new TreeNode('r');
    root->left->right->right = new TreeNode('w');
    root->right->left->left = new TreeNode('d');
    root->right->left->right = new TreeNode('k');
    root->right->right->left = new TreeNode('g');
    root->right->right->right = new TreeNode('o');

    root->left->left->left->left = new TreeNode('h');
    root->left->left->left->right = new TreeNode('v');
    root->left->left->right->left = new TreeNode('f');
    root->left->right->right->left = new TreeNode('p');
    root->left->right->right->right = new TreeNode('j');
    root->right->left->left->left = new TreeNode('b');
    root->right->left->left->right = new TreeNode('x');
    root->right->left->right->left = new TreeNode('c');
    root->right->left->right->right = new TreeNode('y');
    root->right->right->left->left = new TreeNode('z');
    root->right->right->left->right = new TreeNode('q');

    return root;
}

// Encoding a message as per Morse map Tree
std::string MorseCode::encodeMessage(const std::string& message) 
{
    std::stringstream encoded;
    for (char c : message) 
    {
        c = tolower(c); // Convert to lowercase
        if (morseMap.count(c)) 
        {
            encoded << morseMap.at(c) << " ";
        }
    }
    return encoded.str();
}

// Decoding a message as per Morse map Tree
std::string MorseCode::decodeMessage(const std::string& morseCode) 
{
    std::stringstream decoded, input(morseCode);
    std::string symbol;
    TreeNode* current = root;

    while (getline(input, symbol, ' ')) 
    {
        for (char c : symbol) 
        {
            if (c == '.') 
            {
                current = current->left;
            } 
            else if (c == '-') 
            {
                current = current->right;
            }
        }
        if (current && current->letter) 
        {
            decoded << current->letter;
        }
        current = root; 
    }
    return decoded.str();
}


int main() {
    MorseCode morse;

    
    std::cout << "Enter a message: ";
    std::string message;
    std::getline(std::cin, message);
 
    std::string codedMessage = morse.encodeMessage(message);
    std::cout << "Coded message: " << codedMessage << std::endl;

    std::string decodedMessage = morse.decodeMessage(codedMessage);
    std::cout << "Decoded message: " << decodedMessage << std::endl;

    return 0;
}
