#ifndef __LRUCache_t__
#define __LRUCache_t__ 

typedef struct LRUCache_t *LRUCache;

LRUCache LRUInit(int capacite);

int LRUGet(LRUCache * obj, int cle);

void LRUPut(LRUCache * obj, int cle, int valeur);

void LRUFree(LRUCache * obj);

#endif
