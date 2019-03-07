#include <iostream>
struct BstNode {
    int key;
    int value;
    BstNode * parent;
    BstNode * left_child;
    BstNode * right_child;
};

BstNode * create_node(int key, int value) {
    BstNode * root = (BstNode*) malloc(sizeof(BstNode));
    root->key = key;
    root->value = value;
    root->parent = nullptr;
    root->left_child = nullptr;
    root->right_child = nullptr;
    return root;
}

void inorder_tree_walk(BstNode *x) {
    if (x != nullptr) {
        inorder_tree_walk(x->left_child);
        printf("%d ", x->key);
        inorder_tree_walk(x->right_child);
    }
};

void preorder_tree_walk(BstNode *x) {
    if (x != nullptr) {
        preorder_tree_walk(x->right_child);
        printf("key(%d)", x->key);
        preorder_tree_walk(x->left_child);
    }
};

BstNode * tree_search(BstNode *x, int key) {
    if (x == nullptr || key == x->key) {
        return x;
    } else {
        if (key < x->key)
            return tree_search(x->left_child, key);
        else
            return tree_search(x->right_child, key);
    }
}

BstNode * tree_minimum(BstNode * x) {
    while (x->left_child != nullptr) {
        x = x->left_child;
    }
    return x;
}

BstNode * tree_maximum(BstNode * x) {
    while (x->right_child != nullptr) {
        x = x->right_child;
    }
    return x;
}

BstNode * tree_successor(BstNode * x) {
    if(x->right_child != nullptr) {
        return tree_minimum(x->right_child);
    }
    BstNode * y = x->parent;
    while (y != nullptr && x == y->right_child) {
        x = y;
        y = y->parent;
    }
    return y;
}

void tree_insert(BstNode ** root, BstNode * new_node) {
    BstNode * current_node = *root;
    if(current_node == nullptr) {
        *root = new_node;
        return;
    }
    BstNode * parent_of_current = nullptr;
    while (current_node != nullptr) {
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
    BstNode * parent = nullptr;
    BstNode * current_node = nullptr;
    if(node_to_delete->left_child == nullptr || node_to_delete->right_child == nullptr) {
        parent = node_to_delete;
    }
    else {
        parent = tree_successor(node_to_delete);
    }
    if (parent->left_child != nullptr) {
        current_node = parent->left_child;
    }
    else {
        current_node = parent->right_child;
    }
    if(current_node != nullptr) {
        current_node->parent = parent->parent;
    }
    if(parent->parent == nullptr and parent == parent->parent->left_child) {
        parent->parent->left_child = current_node;
    }
}

int is_node_valid(BstNode * node) {
    if (node->parent != nullptr) {
        if(node->parent->left_child == node && node->parent->key < node->key) {
            return 0;
        }
        if(node->parent->right_child == node && node->parent->key > node->key) {
            return 0;
        }
    }
    if(node->right_child != nullptr && node->key > node->right_child->key) {
        return 0;
    }
    if(node->left_child != nullptr && node->key < node->left_child->key) {
        return 0;
    }

    return 1;
}

int is_bst_valid(BstNode * node) {
    int right_valid, left_valid;
    if (node != nullptr) {
        if (is_node_valid(node)) {
            left_valid = is_bst_valid(node->left_child);
            right_valid = is_bst_valid(node->right_child);
            if (left_valid && right_valid) {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}
