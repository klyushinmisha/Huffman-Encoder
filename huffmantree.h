#include <QByteArray>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

typedef struct _TreeNode{
    _TreeNode* left = nullptr;
    _TreeNode* right = nullptr;
    int weight;
    char value;

    _TreeNode(char b, int weight){
        value = b;
        this->weight = weight;
    }

    _TreeNode(_TreeNode* a, _TreeNode* b){
        left = a;
        right = b;
        weight = a->weight + b->weight;
    }

}TreeNode;


class HuffmanTree
{
private:
    TreeNode* head;
    std::list<TreeNode*>* getNodesList(QByteArray);
    void replaceNodes(std::list<TreeNode*>*);

public:
    HuffmanTree(QByteArray);
    TreeNode* getHead();

};

#endif // HUFFMANTREE_H
