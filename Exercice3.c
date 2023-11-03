#include "exercice3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_HASH 100001

// Utilisation des files et des tables de hashage

typedef struct qnode *Qnode;
typedef struct queue *Queue;

struct qnode {
    struct qnode *prev;
    struct qnode *next;
    int cle;
    int data;
} ;


struct queue {
    Qnode *head;
    Qnode *tail;
    int count;
};


struct LRUCache_t{
    int capacite;
    Queue *queue;
    Qnode **hash;
};


Qnode *createNode(int cle, int data)
{
      Qnode *temp = (Qnode *)malloc(sizeof(Qnode));
      temp->prev = NULL;
      temp->next = NULL;
      temp->cle = cle;
      temp->data = data;
      return temp;
}


Queue* createQueue(int number)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    
    queue->head = createNode(-1,0); 
    queue->tail = createNode(-1,0);
    queue->head->next = queue->tail;
    queue->tail->prev = queue->head;
    queue->count = number;
    
    return queue;
}

Qnode ** createHash(int size)
{
    Qnode **hash = (Qnode **)malloc(size * sizeof(Qnode *));
    
    memset(hash, 0, size *sizeof(Qnode *)); 
    
    return hash;
}


void removeNode(LRUCache *cache, Qnode *node)
{
    Qnode *prev = node->prev;
    Qnode *next = node->next;
    
    prev->next = next;
    next->prev = prev;
}

void addNode(LRUCache *cache, Qnode *node)
{
    node->prev = cache->queue->head;
    node->next = cache->queue->head->next;
    
    cache->queue->head->next->prev = node;
    cache->queue->head->next = node;  
}

void moveToHead(LRUCache *cache, Qnode *node)
{
    removeNode(cache,node);
    addNode(cache,node);
    
}

Qnode* popTail(LRUCache *cache)
{
    Qnode *node = cache->queue->tail->prev;
    removeNode(cache,node);
    return node;
}


LRUCache  LRUInit(int capacite){
    LRUCache *lru = (LRUCache *)malloc(sizeof(LRUCache));
    lru->hash = createHash(TAILLE_HASH);
    lru->queue = createQueue(capacite);
    lru->capacite = capacite;
}

int LRUGet(LRUCache * obj, int cle){
    if(obj->hash[cle] != NULL)
    {
        Qnode *node = obj->hash[cle];
        int data = node->data;
        moveToHead(obj,node);
        return data;
    }
    
    return -1;
}

void LRUPut(LRUCache * obj, int cle, int valeur){
    
    Qnode *node = obj->hash[cle];
    
   if(!node)
   {
       node = createNode(cle,valeur);
       obj->hash[cle] = node;
       addNode(obj,node);
       obj->queue->count++;
       
       if(obj->queue->count > obj->capacity)
       {
           Qnode *tail = popTail(obj);
           obj->hash[tail->cle] = NULL;
           obj->queue->count--;
       }
   }
   else{
        
       node->data = valeur; 
       moveToHead(obj,node);
    }
}

void LRUFree(LRUCache * obj){
    while(obj->queue->head)
    {
        Qnode * temp = obj->queue->head;
        obj->queue->head = obj->queue->head->next;
        free(temp);
    }
    
    free(obj->queue);
    free(obj->hash);
    free(obj);
}

int main(void)
{


    return 0;
}

