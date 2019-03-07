typedef struct BstNode BstNode;
struct BstNode {
    int key;
    int value;
    BstNode * parent;
    BstNode * left_child;
    BstNode * right_child;
};

