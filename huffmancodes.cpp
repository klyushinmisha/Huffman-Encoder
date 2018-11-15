#include "huffmancodes.h"
#include <QString>

HuffmanCodes::HuffmanCodes(){}

HuffmanCodes::HuffmanCodes(TreeNode* head)
{
    codes = new std::map<char, Code*>();
    treeWork(head, 0, 0);
}

Code* HuffmanCodes::operator[](char b)
{
    return codes->at(b);
}

QString HuffmanCodes::toString()
{
    QString buf;
    for (auto i = codes->begin(); i != codes->end(); i++){
        QString tmp = QString::number(static_cast<char>((*i).second->value), 2);
        for (int j = (*i).second->length - tmp.length(); j > 0; j--) tmp = "0" + tmp;
        buf += "0x" + QString::number(static_cast<int>((*i).first), 16) + " — " + tmp + "\n";
    }
    return buf;
}

void HuffmanCodes::treeWork(TreeNode* tn, char code, int height)
{
    if (tn->left == nullptr){
        codes->insert(std::make_pair(tn->value, new Code(code, height)));
    } else {
        char nCode = static_cast<char>(code | (1 << height));
        treeWork(tn->left, code, height + 1);
        treeWork(tn->right, nCode, height + 1);
    }
}
