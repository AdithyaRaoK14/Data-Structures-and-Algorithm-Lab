#ifndef _INCLUDED_DLL_
#define _INCLUDED_DLL_
#include <stdint.h>
#include <stddef.h> 
// Node structure
typedef struct _dnode_ {
    int32_t data;
    struct _dnode_ *prev;
    struct _dnode_ *next;
} DNode;

// DLL structure
typedef struct _dll_ {
    DNode *head;
    DNode *tail;
} DLL;

// Function prototypes
DLL dll_new();
DLL* dll_add(DLL *list, int32_t data);
DLL* dll_delete(DLL *list, int32_t data);
void dll_free(DLL *list);

#endif
