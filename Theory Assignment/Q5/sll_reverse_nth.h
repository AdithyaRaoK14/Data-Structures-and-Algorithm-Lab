#ifndef _INCLUDED_SLL_REVERSE_NTH_
#define _INCLUDED_SLL_REVERSE_NTH_
#include <stdint.h>
#include <stddef.h>
// Node structure
typedef struct _rnode_ {
    int32_t data;
    struct _rnode_ *next;
} RNode;

// List structure
typedef struct _rlist_ {
    RNode *head;
} RList;

// Function prototypes
RList rlist_new();
RList* rlist_insert(RList *list, int32_t data);
void rlist_reverse(RList *list);
int32_t rlist_nth_from_end(RList *list, int32_t n);
void rlist_free(RList *list);

#endif
