#ifndef _INCLUDED_HASH_
#define _INCLUDED_HASH_
#include <stdint.h>

typedef struct _list_node_ List;
typedef struct _hash_table_ HashTable;

struct _list_node_ {
    char element[30];
    List *next;
};

struct _hash_table_ {
    uint32_t tablesize;
    List **theLists;
};

HashTable hashtable_new(uint32_t size);
uint32_t hashtable_find(HashTable *htb, char *element);
HashTable *hashtable_insert_element(HashTable *htb, char *element);
HashTable *hashtable_delete_element(HashTable *htb, char *element);
void hashtable_destroy(HashTable *htb);

#endif
