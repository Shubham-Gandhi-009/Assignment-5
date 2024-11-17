Author : Shubham M.Gandhi 
Student ID: 200526729     

Morse Code Encoder and Decoder   

Description:
            This project implements a Morse code encoder and decoder in C++. It uses a binary tree structure to store Morse code and maps each character of the English alphabet to its corresponding Morse code representation. The program allows users to:

            1. Encode plain text messages into Morse code.
            2. Decode Morse code back into plain text.

Files:
1. Header File: MorseCode.h
   - Defines the TreeNode structure and the MorseCode class.
   - Includes function declarations for encoding and decoding messages.

2. Implementation File: MorseCode.cpp
   - Implements the TreeNode constructor.
   - Implements the MorseCode constructor, destructor, and other member functions:
     + buildMorseTree(): Builds the binary tree representation of Morse code.
     + encodeMessage(): Encodes a plain text message into Morse code.
     + decodeMessage(): Decodes Morse code into plain text.
     + deleteTree(): Frees up memory by deleting the binary tree.

    3. Main Program
        - Takes a user input message.
        - Encodes the message into Morse code.
        - Decodes the Morse code back into plain text.
        - Displays the encoded and decoded messages.

Example Input/Output
Input: 
Enter a message: Hello World

Output:
Coded message: .... . .-.. .-.. ---   .-- --- .-. .-.. -..
Decoded message: hello world

Features:
        1. Morse Code Encoding: Converts plain text into Morse code using a predefined binary tree and a lookup table.
        2. Morse Code Decoding: Decodes Morse code into plain text using the binary tree.
        3. Robust Design:
        4. Case-insensitive: Converts all input characters to lowercase.
        5. Spaces in Morse code are interpreted correctly for separating words and characters.
        6. Tree-Based Structure:
        7. The Morse code tree represents the hierarchy of dots (.) and dashes (-).

Morse Code Representation
Each letter of the alphabet is mapped to Morse code. Below is the encoding used in the program:

Letter	Morse Code	Letter	Morse Code
A	    .-	        N	    -.
B	    -...	    O	    ---
C	    -.-.	    P	    .--.
D	    -..	        Q	    --.-
E	    .	        R	    .-.
F	    ..-.	    S	    ...
G	    --.	        T	    -
H	    ....	    U	    ..-
I	    ..	        V	    ...-
J	    .---	    W	    .--
K	    -.-	        X	    -..-
L	    .-..	    Y	    -.--
M	    --	        Z	    --..


GitHub Repository Link : https://github.com/Shubham-Gandhi-009/Assignment-5
