#include "huffmancodes.h"

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
        QString tmp = QString::number(static_cast<ushort>((*i).second->value), 2);
        for (int j = (*i).second->length - tmp.length(); j > 0; j--) tmp = "0" + tmp;
        buf += "0x" + QString::number(static_cast<uchar>((*i).first), 16) + " — " + tmp + "\n";
    }
    return buf;
}

void HuffmanCodes::treeWork(TreeNode* tn, ushort code, int height)
{
    if (tn->left == nullptr){
        codes->insert(std::make_pair(tn->value, new Code(code, height)));
    } else {
        ushort nCode = static_cast<ushort>(code | (1 << height));
        treeWork(tn->left, code, height + 1);
        treeWork(tn->right, nCode, height + 1);
    }
}
