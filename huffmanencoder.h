#ifndef HUFFMANENCODER_H
#define HUFFMANENCODER_H

#include <huffmancodes.h>

class HuffmanEncoder
{
private:
    HuffmanCodes codes;

public:
    HuffmanEncoder(HuffmanCodes&);
};

#endif // HUFFMANENCODER_H
