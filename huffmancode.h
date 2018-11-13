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

class HuffmanCode
{
private:
    std::map<char, Code*>* codes;

public:
    HuffmanCode(TreeNode*, QString& s);
    Code* operator[](char);
    void treeWork(TreeNode*, char, int);
};

#endif // HUFFMANCODE_H
