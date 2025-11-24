// bst.h
// Binary Search Tree header
 
#ifndef BST_H
#define BST_H
 
#include <stdint.h>
#include <stdbool.h>
 
// -------------------- Structs --------------------
 
typedef struct TreeNode {
    int32_t key;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
 
typedef struct BST {
    TreeNode *root;
    uint32_t size;
} BST;
 
// -------------------- Core Operations --------------------
 
BST        bst_new(void);
void       bst_insert(BST *tree, int32_t key);
TreeNode*  bst_find(const BST *tree, int32_t key);
void       bst_delete(BST *tree, int32_t key);
uint32_t   bst_size(const BST *tree);
uint32_t   bst_height(const BST *tree);
void       bst_free(BST *tree);
 
// -------------------- Traversals --------------------
 
void inorder_recursive(const TreeNode *root);
void preorder_recursive(const TreeNode *root);
void postorder_recursive(const TreeNode *root);
void inorder_iterative(const TreeNode *root);
void level_order(const TreeNode *root);
 
#endif // BST_H