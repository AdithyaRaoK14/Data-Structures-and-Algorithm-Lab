#include "hashing.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

HASHTABLE HT_new(int size){
	HASHTABLE H;
	H.size = size;
	H.lists = (NODE**)malloc(sizeof(NODE*)*H.size);
	for(int i = 0; i < H.size;i++){
		H.lists[i] = NULL;
	}
	return H;
}

int hash(char *key, int size){
	int hashval = 0;
	while(*key!='\0'){
		hashval += *key++;
	}
	return hashval % size;
}

int HT_find(HASHTABLE *htb,char *element){
	NODE *node=htb->lists[hash(element,htb->size)];
	while(node!=NULL){
		if(!strcmp(node->element,element)){
			return 1;
		}else{
			node=node->next;
		}
	}return 0;
}

HASHTABLE *HT_insert(HASHTABLE *htb,char *element){
	if(!HT_find(htb,element)){
		int bucket = hash(element,htb->size);
		NODE *oldHead = htb->lists[bucket];
		NODE *node = (NODE*)malloc(sizeof(NODE));
		strcpy(node->element,element);
		node->next=oldHead;
		htb->lists[bucket]=node;
	}return htb;
}

HASHTABLE *HT_delete(HASHTABLE *htb, char *element){
	int bucket = hash(element,htb->size);
	NODE *temp, *current;
	if(htb->lists[bucket]!=NULL){
		if(!strcmp(htb->lists[bucket]->element,element)){
			temp = htb->lists[bucket];
			htb->lists[bucket]=htb->lists[bucket]->next;
			free(temp);
		}else{
			current = htb->lists[bucket];
			while(current->next!=NULL){
				if(!strcmp(current->next->element,element)){
					temp=current->next;
					current->next=current->next->next;
					free(temp);
					break;
				}else{
					current=current->next;
				}
			}
		}
	}return htb;
}

void HT_display(HASHTABLE *htb) {
    if (htb == NULL) {
        printf("Hash table is NULL.\n");
        return;
    }

    printf("\n----- HASH TABLE -----\n");

    for (int i = 0; i < htb->size; i++) {
        printf("Bucket %d: ", i);

        NODE *current = htb->lists[i];

        if (current == NULL) {
            printf("EMPTY\n");
            continue;
        }

        // Print the linked list in this bucket
        while (current != NULL) {
            printf("%s -> ", current->element);
            current = current->next;
        }

        printf("NULL\n");
    }

    printf("----------------------\n\n");
}


void HT_destroy(HASHTABLE *htb){
	NODE *current,*temp;
	for(int i=0;i<htb->size;++i){
		current=htb->lists[i];
		while(current!=NULL){
			temp = current;
			current=current->next;
			free(temp);
		}
	}free(htb->lists);
}