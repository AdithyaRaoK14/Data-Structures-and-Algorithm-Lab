// bst.c
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
 
/* ----------------- Utility: node creation ----------------- */
 
static TreeNode *tree_node_new(int32_t key) {
    TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode));
    if (!n) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }
    n->key = key;
    n->left = n->right = NULL;
    return n;
}
 
/* ----------------- BST: basic constructors ----------------- */
 
BST bst_new(void) {
    BST t;
    t.root = NULL;
    t.size = 0;
    return t;
}
 
/* ----------------- BST: insert (iterative) ----------------- */
 
void bst_insert(BST *tree, int32_t key) {
    if (!tree) return;
 
    TreeNode *parent = NULL;
    TreeNode *cur = tree->root;
 
    while (cur != NULL) {
        parent = cur;
        if (key < cur->key) cur = cur->left;
        else if (key > cur->key) cur = cur->right;
        else return; // key exists, ignore
    }
 
    TreeNode *node = tree_node_new(key);
    if (parent == NULL) {
        tree->root = node;
    } else if (key < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    tree->size++;
}
 
/* ----------------- BST: find ----------------- */
 
TreeNode *bst_find(const BST *tree, int32_t key) {
    if (!tree) return NULL;
    TreeNode *cur = tree->root;
    while (cur) {
        if (key == cur->key) return cur;
        if (key < cur->key) cur = cur->left;
        else cur = cur->right;
    }
    return NULL;
}
 
/* ----------------- BST: size ----------------- */
 
uint32_t bst_size(const BST *tree) {
    return tree ? tree->size : 0;
}
 
/* ----------------- BST: height ----------------- */
 
static int32_t node_height(const TreeNode *n) {
    if (!n) return 0;
    int32_t lh = node_height(n->left);
    int32_t rh = node_height(n->right);
    return (lh > rh ? lh : rh) + 1;
}
 
uint32_t bst_height(const BST *tree) {
    if (!tree || !tree->root) return 0;
    return (uint32_t)node_height(tree->root);
}
 
/* ----------------- Delete helpers ----------------- */
 
static TreeNode *find_min(TreeNode *n) {
    if (!n) return NULL;
    while (n->left) n = n->left;
    return n;
}
 
static TreeNode *bst_delete_recursive(TreeNode *root, int32_t key, bool *deleted) {
    if (!root) return NULL;
 
    if (key < root->key)
        root->left = bst_delete_recursive(root->left, key, deleted);
    else if (key > root->key)
        root->right = bst_delete_recursive(root->right, key, deleted);
    else {
        *deleted = true;
        if (!root->left) {
            TreeNode *r = root->right;
            free(root);
            return r;
        } else if (!root->right) {
            TreeNode *l = root->left;
            free(root);
            return l;
        } else {
            TreeNode *succ = find_min(root->right);
            root->key = succ->key;
            root->right = bst_delete_recursive(root->right, succ->key, deleted);
        }
    }
    return root;
}
 
void bst_delete(BST *tree, int32_t key) {
    if (!tree || !tree->root) return;
    bool deleted = false;
    tree->root = bst_delete_recursive(tree->root, key, &deleted);
    if (deleted && tree->size > 0) tree->size--;
}
 
/* ----------------- Traversals ----------------- */
 
void inorder_recursive(const TreeNode *root) {
    if (!root) return;
    inorder_recursive(root->left);
    printf("%d ", root->key);
    inorder_recursive(root->right);
}
 
void preorder_recursive(const TreeNode *root) {
    if (!root) return;
    printf("%d ", root->key);
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}
 
void postorder_recursive(const TreeNode *root) {
    if (!root) return;
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    printf("%d ", root->key);
}
 
/* Iterative inorder (stack) */
typedef struct NodeStack {
    TreeNode **arr;
    size_t cap;
    size_t top;
} NodeStack;
 
static NodeStack *stack_new(size_t cap) {
    NodeStack *s = malloc(sizeof(NodeStack));
    s->cap = cap ? cap : 64;
    s->arr = malloc(sizeof(TreeNode *) * s->cap);
    s->top = 0;
    return s;
}
 
static void stack_push(NodeStack *s, TreeNode *n) {
    if (s->top >= s->cap) {
        s->cap *= 2;
        s->arr = realloc(s->arr, sizeof(TreeNode *) * s->cap);
    }
    s->arr[s->top++] = n;
}
 
static TreeNode *stack_pop(NodeStack *s) {
    return s->top ? s->arr[--s->top] : NULL;
}
 
static bool stack_empty(NodeStack *s) {
    return s->top == 0;
}
 
static void stack_free(NodeStack *s) {
    free(s->arr);
    free(s);
}
 
void inorder_iterative(const TreeNode *root) {
    NodeStack *st = stack_new(64);
    const TreeNode *cur = root;
    while (cur || !stack_empty(st)) {
        while (cur) {
            stack_push(st, (TreeNode *)cur);
            cur = cur->left;
        }
        TreeNode *n = stack_pop(st);
        printf("%d ", n->key);
        cur = n->right;
    }
    stack_free(st);
}
 
/* Level order (queue) */
typedef struct NodeQueue {
    TreeNode **arr;
    size_t cap;
    size_t head, tail, count;
} NodeQueue;
 
static NodeQueue *queue_new(size_t cap) {
    NodeQueue *q = malloc(sizeof(NodeQueue));
    q->cap = cap ? cap : 64;
    q->arr = malloc(sizeof(TreeNode *) * q->cap);
    q->head = q->tail = q->count = 0;
    return q;
}
 
static void queue_enqueue(NodeQueue *q, TreeNode *n) {
    if (q->count == q->cap) {
        size_t newcap = q->cap * 2;
        TreeNode **newarr = malloc(sizeof(TreeNode *) * newcap);
        for (size_t i = 0; i < q->count; ++i)
            newarr[i] = q->arr[(q->head + i) % q->cap];
        free(q->arr);
        q->arr = newarr;
        q->cap = newcap;
        q->head = 0;
        q->tail = q->count;
    }
    q->arr[q->tail] = n;
    q->tail = (q->tail + 1) % q->cap;
    q->count++;
}
 
static TreeNode *queue_dequeue(NodeQueue *q) {
    if (!q->count) return NULL;
    TreeNode *n = q->arr[q->head];
    q->head = (q->head + 1) % q->cap;
    q->count--;
    return n;
}
 
static bool queue_empty(NodeQueue *q) {
    return q->count == 0;
}
 
static void queue_free(NodeQueue *q) {
    free(q->arr);
    free(q);
}
 
void level_order(const TreeNode *root) {
    if (!root) return;
    NodeQueue *q = queue_new(64);
    queue_enqueue(q, (TreeNode *)root);
    while (!queue_empty(q)) {
        TreeNode *n = queue_dequeue(q);
        printf("%d ", n->key);
        if (n->left) queue_enqueue(q, n->left);
        if (n->right) queue_enqueue(q, n->right);
    }
    queue_free(q);
}
 
/* ----------------- Free ----------------- */
 
static void free_subtree(TreeNode *root) {
    if (!root) return;
    free_subtree(root->left);
    free_subtree(root->right);
    free(root);
}
 
void bst_free(BST *tree) {
    if (!tree) return;
    free_subtree(tree->root);
    tree->root = NULL;
    tree->size = 0;
}