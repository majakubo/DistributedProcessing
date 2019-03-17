//
// Created by majaku on 17.03.19.
//

#ifndef UNTITLED_BST_H
#define UNTITLED_BST_H
#include "bstNode.h"
BstNode * create_node(int key, int value);
void inorder_tree_walk(BstNode *x);
void preorder_tree_walk(BstNode *x);
BstNode * tree_search(BstNode *x, int key);
BstNode * tree_minimum(BstNode * x);
BstNode * tree_maximum(BstNode * x);
BstNode * tree_successor(BstNode * x);
void tree_insert(BstNode ** root, BstNode * new_node);
void tree_delete(BstNode * root, BstNode * node_to_delete);
int is_node_valid(BstNode * node);
int isBST(BstNode * node, int minKey, int maxKey);


#endif //UNTITLED_BST_H
