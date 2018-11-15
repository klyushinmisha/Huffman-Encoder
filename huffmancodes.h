#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H

#include <huffmantree.h>
#include <QString>

typedef struct _Code{
    ushort value;
    int length;

    _Code(ushort value, int length){
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
    void treeWork(TreeNode*, ushort, int);
};

#endif // HUFFMANCODE_H
