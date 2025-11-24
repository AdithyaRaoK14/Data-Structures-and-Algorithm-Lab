// test_bst.c
#include "bst.h"
#include <assert.h>
#include <stdio.h>
 
int main(void) {
    BST tree = bst_new();
    assert(bst_size(&tree) == 0);
    assert(bst_height(&tree) == 0);
 
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; ++i) bst_insert(&tree, vals[i]);
 
    assert(bst_size(&tree) == 7);
    assert(bst_find(&tree, 60) != NULL);
    assert(bst_find(&tree, 999) == NULL);
    assert(bst_height(&tree) == 3);
 
    printf("Inorder before delete: ");
    inorder_recursive(tree.root);
    printf("\n");
 
    bst_delete(&tree, 30);  // delete node with two children
    assert(bst_size(&tree) == 6);
    assert(bst_find(&tree, 30) == NULL);
 
    bst_delete(&tree, 20);  // delete leaf
    bst_delete(&tree, 70);  // delete node with right child
    assert(bst_size(&tree) == 4);
 
    printf("Inorder after delete: ");
    inorder_recursive(tree.root);
    printf("\n");
 
    printf("Level-order traversal: ");
    level_order(tree.root);
    printf("\n");
 
    // Test insertion of duplicate (should not change size)
    bst_insert(&tree, 50);
    assert(bst_size(&tree) == 4);
 
    // Clean up
    bst_free(&tree);
    assert(tree.size == 0);
    assert(tree.root == NULL);
 
    printf("\n All BST tests passed successfully!\n");
    return 0;
}