//
// Created by majaku on 03.03.19.
//
#include "bst.h"
#include "bstnode.h"
#include <stdio.h>
BstNode * create_proper_bst() {
    BstNode * root = nullptr;
    tree_insert(&root, create_node(4,4));
    tree_insert(&root, create_node(2,4));
    tree_insert(&root, create_node(6,4));
    tree_insert(&root, create_node(1,4));
    tree_insert(&root, create_node(3,4));
    tree_insert(&root, create_node(5,4));
    tree_insert(&root, create_node(7,4));
    return root;
}

void test1() {
    BstNode * root = create_proper_bst();
    inorder_tree_walk(root);
    printf("test  1 is --> %d\n", is_bst_valid(root));
}

void test2() {
    BstNode * root = create_proper_bst();
    root->right_child->right_child->key = 4;
    inorder_tree_walk(root);
    printf("test  2 is --> %d\n", is_bst_valid(root));
}

void test3() {
    BstNode * root = create_proper_bst();
    root->right_child->left_child->key = 8;
    inorder_tree_walk(root);
    printf("test  3 is --> %d\n", is_bst_valid(root));
}

void test4() {
    BstNode * root = create_proper_bst();
    root->left_child->right_child->key = 0;
    inorder_tree_walk(root);
    printf("test  4 is --> %d\n", is_bst_valid(root));
}

void test5() {
    BstNode * root = create_proper_bst();
    root->left_child->left_child->key = 4;
    inorder_tree_walk(root);
    printf("test  5 is --> %d\n", is_bst_valid(root));
}

void test6() {
    BstNode * root = create_proper_bst();
    root->right_child->key = 1;
    inorder_tree_walk(root);
    printf("test  6 is --> %d\n", is_bst_valid(root));
}

void test7() {
    BstNode * root = create_proper_bst();
    root->right_child->key = 1;
    inorder_tree_walk(root);
    printf("test  7 is --> %d\n", is_bst_valid(root));
}
void test8() {
    BstNode * root = create_proper_bst();
    root->left_child->key = 7;
    inorder_tree_walk(root);
    printf("test  8 is --> %d\n", is_bst_valid(root));
}

void test9() {
    BstNode * root = create_proper_bst();
    root->left_child->key = 0;
    inorder_tree_walk(root);
    printf("test  9 is --> %d\n", is_bst_valid(root));
}

void test10() {
    BstNode * root = create_proper_bst();
    root->key = 8;
    inorder_tree_walk(root);
    printf("test 10 is --> %d\n", is_bst_valid(root));
}
void test11() {
    BstNode * root = create_proper_bst();
    root->key = 1;
    inorder_tree_walk(root);
    printf("test 11 is --> %d\n", is_bst_valid(root));
}
