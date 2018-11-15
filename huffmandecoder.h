#ifndef HUFFMANDECODER_H
#define HUFFMANDECODER_H

#include <huffmancodes.h>

class HuffmanDecoder
{
public:
    HuffmanDecoder(HuffmanCodes);
    void run(QByteArray);
};

#endif // HUFFMANDECODER_H
