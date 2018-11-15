#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H

#include <huffmantree.h>
#include <QString>

typedef struct _Code{
    char value;
    int length;

    _Code(char value, int length){
        this->value = value;
        this->length = length;
    }

}Code;

class HuffmanCodes
{
private:
    std::map<char, Code*>* codes;

public:
    HuffmanCodes();
    HuffmanCodes(TreeNode*);
    Code* operator[](char);
    QString toString();
    void treeWork(TreeNode*, char, int);
};

#endif // HUFFMANCODE_H
