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

MList mlist_new();
MList* mlist_insert(MList *list, int32_t data);
int32_t mlist_min(MList *list);
int32_t mlist_max(MList *list);
void mlist_free(MList *list);

#endif
