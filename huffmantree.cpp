#include "huffmantree.h"

HuffmanTree::HuffmanTree(QByteArray bytes){
    std::list<TreeNode*>* nodes = getNodesList(bytes);

    nodes->sort(
          [](TreeNode* a, TreeNode* b) -> bool{ return a->weight < b->weight; });

    replaceNodes(nodes);

    head = *nodes->begin();
}

std::list<TreeNode*> *HuffmanTree::getNodesList(QByteArray bytes){
    std::list<TreeNode*>* nodes = new std::list<TreeNode*>();
    std::vector<int> gist(256);

    for (char b : bytes){
        gist[static_cast<uint>(reinterpret_cast<uchar&>(b))] += 1;
    }

    uchar i = 0;
    do {
        if (gist.at(static_cast<uint>(i)) != 0){
            nodes->push_back(new TreeNode(reinterpret_cast<char&>(i),
                                          gist.at(static_cast<uint>(i))));
        }
    } while (++i > 0);

    return nodes;
}

void HuffmanTree::replaceNodes(std::list<TreeNode*>* nodes){
    while (nodes->size() > 1){
        TreeNode* m1 = *nodes->begin();
        nodes->remove(m1);

        TreeNode* m2 = *nodes->begin();
        nodes->remove(m2);

        TreeNode* localP = new TreeNode(m1, m2);

        auto iter = nodes->begin();
        for (; iter != nodes->end(); iter++){
            if ((*iter)->weight > localP->weight){
                break;
            }
        }
        if (iter != nodes->end()){
            nodes->insert(iter, localP);
        } else {
            nodes->push_back(localP);
        }
    }
}

TreeNode *HuffmanTree::getHead(){
    return head;
}
