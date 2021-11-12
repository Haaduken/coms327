#include <stdlib.h>
#include <stdio.h>
#include "binaryTree.h"

TREEPTR createTree(){
    TREEPRT tree = malloc(sizeof(TREE));
    if(!tree) return NULL;
    tree -> numItems =0;
    tree->root = NULL;
    return tree;
}

int addTreeItem(TREEPTR t, void* item, int(*comp)(void*, void*)){
    if(t->root == NULL){
        t->root = malloc(sizeof(NODE));
        if(t->root==NULL)return NULL;
        t->root->data = item;
        t->root->left = NULL;
        t->root->right = NULL;
    }
    else{
        t->root = addrec(t->root, item, comp);
    }
    t->numItems+=1;
    return 1;
}

NODEPTR addrec(NODEPTR r, void* itemToAdd, int (*comp)(void*, void*)){
    if(r==null){
        NODEPTR addnode = malloc(sizeof(NODE));
        addnode->data = itemToAdd;
        addnode->left = NULL;
        addnode->right = NULL;
    }
}