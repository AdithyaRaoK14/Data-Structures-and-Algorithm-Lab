#ifndef _INCLUDED_SLL_MINMAX_
#define _INCLUDED_SLL_MINMAX_

#include <stdint.h>

typedef struct _mnode_ {
    int32_t data;
    struct _mnode_ *next;
} MNode;

typedef struct _mlist_ {
    MNode *head;
    int32_t min_val;
    int32_t max_val;
} MList;

MList mlist_new();                           // Create a new list
MList* mlist_add_head(MList *list, int32_t data); // Insert at the head
int32_t mlist_get_min(MList *list);                // Get minimum value
int32_t mlist_get_max(MList *list);                // Get maximum value
void mlist_free(MList *list);                    // Free the list
void mlist_print(MList *list);  

#endif
