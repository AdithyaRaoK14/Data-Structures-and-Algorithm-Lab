#include "hashing.h"
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

static uint32_t _hash_(char *key, uint32_t tablesize) {
    uint32_t hashval = 0;
    while (*key != '\0') {
        hashval += *key++;
    }
    return hashval % tablesize;
}

HashTable hashtable_new(uint32_t size) {
    HashTable H;
    int i;
    H.tablesize = size;
    H.theLists = (List **)malloc(sizeof(List *) * H.tablesize);
    for (i = 0; i < H.tablesize; i++) {
        H.theLists[i] = NULL;
    }
    return H;
}

uint32_t hashtable_find(HashTable *htb, char *key) {
    List *list = htb->theLists[_hash_(key, htb->tablesize)];
    while (list != NULL) {
        if (!strcmp(list->element, key)) {
            return 1;
        } else {
            list = list->next;
        }
    }
    return 0;
}

HashTable *hashtable_insert_element(HashTable *htb, char *data) {
    uint32_t bucket;
    List *oldAddress;
    if (!hashtable_find(htb, data)) {
        bucket = _hash_(data, htb->tablesize);
        oldAddress = htb->theLists[bucket];
        htb->theLists[bucket] = (List *)malloc(sizeof(List));
        strcpy(htb->theLists[bucket]->element, data);
        htb->theLists[bucket]->next = oldAddress;
    }
    return htb;
}

HashTable *hashtable_delete_element(HashTable *htb, char *data) {
    List *current, *temp;
    uint32_t bucket = _hash_(data, htb->tablesize);
    if (htb->theLists[bucket] != NULL) {
        if (!strcmp(htb->theLists[bucket]->element, data)) {
            temp = htb->theLists[bucket];
            htb->theLists[bucket] = htb->theLists[bucket]->next;
            free(temp);
        } else {
            current = htb->theLists[bucket];
            while (current->next != NULL) {
                if (!strcmp(current->next->element, data)) {
                    temp = current->next;
                    current->next = current->next->next;
                    free(temp);
                    break;
                } else {
                    current = current->next;
                }
            }
        }
    }
    return htb;
}

void hashtable_destroy(HashTable *htb) {
    int i;
    List *current, *temp;
    for (i = 0; i < htb->tablesize; ++i) {
        current = htb->theLists[i];
        while (current != NULL) {
            temp = current;
            current = current->next;
            free(temp);
        }
        free(htb->theLists[i]);
    }
    free(htb->theLists);  // Free the array of lists
}
