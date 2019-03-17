//
// Created by majaku on 17.03.19.
//

#ifndef UNTITLED_BSTNODE_H
#define UNTITLED_BSTNODE_H
typedef struct BstNode BstNode;

struct BstNode {
    int key;
    int value;
    BstNode * parent;
    BstNode * left_child;
    BstNode * right_child;
};


#endif //UNTITLED_BSTNODE_H
