#include "huffmantree.h"

HuffmanTree::HuffmanTree(QByteArray bytes){
    std::list<TreeNode*>* nodes = getNodesList(bytes);

    while (nodes->size() > 1){
        replaceWithParent(nodes);
    }

    head = *nodes->begin();
}

std::list<TreeNode*> *HuffmanTree::getNodesList(QByteArray bytes){
    std::list<TreeNode*>* nodes = new std::list<TreeNode*>();

    for (char b : bytes){
        bool inNodes = false;
        for (TreeNode* t : *nodes){
            if (t->value == b){
                t->weight++;
                inNodes = true;
                break;
            }
        }
        if (!inNodes){
            nodes->push_back(new TreeNode(b));
        }
    }

    return nodes;
}

void HuffmanTree::replaceWithParent(std::list<TreeNode*>* nodes){
    nodes->sort([](TreeNode* a, TreeNode* b) -> bool{ return a->weight < b->weight; });

    TreeNode* m1 = *nodes->begin();
    nodes->remove(m1);

    TreeNode* m2 = *nodes->begin();
    nodes->remove(m2);

    TreeNode* localP = new TreeNode(m1, m2);
    nodes->push_back(localP);
}

TreeNode *HuffmanTree::getHead(){
    return head;
}
