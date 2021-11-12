//Binary Search tree
#ifndef binarytree_h
#define binarytree_h
#ifndef NULL
#define NULL 0
#endif

typedef struct node_t NODE;
typedef struct node_t *NODEPTR;
struct node_t{
    void* data;
    NODEPTR left;
    NODEPTR right;
};

typedef struct tree_t TREE;
typedef struct tree_t *TREEPTR;
struct tree_t{
    NODEPTR root;
    int numItems;
};

TREEPTR createTree();
int addTreeItem(TREEPTR t, void* item, int (*comp)(void*a))