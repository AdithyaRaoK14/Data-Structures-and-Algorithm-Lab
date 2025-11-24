#ifndef _HASHING_
#define _HASHING_

typedef struct NODE{
	char element[30];
	struct NODE *next;
}NODE;

typedef struct HASHTABLE{
	int size;
	NODE **lists;
}HASHTABLE;

HASHTABLE HT_new(int size);
HASHTABLE *HT_insert(HASHTABLE *htb, char *element);
HASHTABLE *HT_delete(HASHTABLE *htb, char *element);
int HT_find(HASHTABLE *htb, char *element);
void HT_display(HASHTABLE *htb);
void HT_destroy(HASHTABLE *htb);

#endif
