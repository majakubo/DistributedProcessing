//
// Created by majaku on 17.03.19.
//
#include <stddef.h>
#include <stdio.h>
#include "bstNode.h"
BstNode * create_node(int key, int value) {
    BstNode * root = (BstNode*) malloc(sizeof(BstNode));
    root->key = key;
    root->value = value;
    root->parent = NULL;
    root->left_child = NULL;
    root->right_child = NULL;
    return root;
}

void inorder_tree_walk(BstNode *x) {
    if (x != NULL) {
        inorder_tree_walk(x->left_child);
        printf("%d ", x->key);
        inorder_tree_walk(x->right_child);
    }
};

void preorder_tree_walk(BstNode *x) {
    if (x != NULL) {
        preorder_tree_walk(x->right_child);
        printf("key(%d)", x->key);
        preorder_tree_walk(x->left_child);
    }
};

BstNode * tree_search(BstNode *x, int key) {
    if (x == NULL || key == x->key) {
        return x;
    } else {
        if (key < x->key)
            return tree_search(x->left_child, key);
        else
            return tree_search(x->right_child, key);
    }
}

BstNode * tree_minimum(BstNode * x) {
    while (x->left_child != NULL) {
        x = x->left_child;
    }
    return x;
}

BstNode * tree_maximum(BstNode * x) {
    while (x->right_child != NULL) {
        x = x->right_child;
    }
    return x;
}

BstNode * tree_successor(BstNode * x) {
    if(x->right_child != NULL) {
        return tree_minimum(x->right_child);
    }
    BstNode * y = x->parent;
    while (y != NULL && x == y->right_child) {
        x = y;
        y = y->parent;
    }
    return y;
}

void tree_insert(BstNode ** root, BstNode * new_node) {
    BstNode * current_node = *root;
    if(current_node == NULL) {
        *root = new_node;
        return;
    }
    BstNode * parent_of_current = NULL;
    while (current_node != NULL) {
        parent_of_current = current_node;

        if (new_node->key < current_node->key) {
            current_node = current_node->left_child;
        }
        else {
            current_node = current_node->right_child;
        }
    }
    new_node->parent = parent_of_current;
    if (new_node->key < parent_of_current->key) {
        parent_of_current->left_child = new_node;
    }
    else {
        parent_of_current->right_child = new_node;
    }
}

void tree_delete(BstNode * root, BstNode * node_to_delete) {
    BstNode * parent = NULL;
    BstNode * current_node = NULL;
    if(node_to_delete->left_child == NULL || node_to_delete->right_child == NULL) {
        parent = node_to_delete;
    }
    else {
        parent = tree_successor(node_to_delete);
    }
    if (parent->left_child != NULL) {
        current_node = parent->left_child;
    }
    else {
        current_node = parent->right_child;
    }
    if(current_node != NULL) {
        current_node->parent = parent->parent;
    }
    if(parent->parent == NULL && parent == parent->parent->left_child) {
        parent->parent->left_child = current_node;
    }
}

int is_node_valid(BstNode * node) {
    if (node->parent != NULL) {
        if(node->parent->left_child == node && node->parent->key < node->key) {
            return 0;
        }
        if(node->parent->right_child == node && node->parent->key > node->key) {
            return 0;
        }
    }
    if(node->right_child != NULL && node->key > node->right_child->key) {
        return 0;
    }
    if(node->left_child != NULL && node->key < node->left_child->key) {
        return 0;
    }

    return 1;
}

int isBST(struct BstNode * node, int minKey, int maxKey) {
    if (node == NULL) return 1;
    if (node->key < minKey || node->key > maxKey)
        return 0;
    return isBST(node->left_child, minKey, node->key-1) && isBST(node->right_child, node->key+1, maxKey);
}
