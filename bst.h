#ifndef BST_BST_H
#define BST_BST_H
struct BstNode {
    int key;
    int value;
    BstNode * parent;
    BstNode * left_child;
    BstNode * right_child;
};
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
int is_bst_valid(BstNode * node);
#endif //BST_BST_H
