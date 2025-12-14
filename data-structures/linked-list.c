#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* next;
    struct node* prev;
} node;

typedef struct {
    node* head;
    node* tail;
    int size;  
} list;

void initList(list* l) {

}

void insertHead(list* l, int item) {

}

void removeHead(list* l, int item) {

}

void insertTail(list* l, int item) {

}

void removeTail(list* l, int item) {

}

bool contains(list *l, int key) {
    return false;
}

void freeList(list* l) {
    node* tmp = l->head;
    while (tmp) {
        node* p = tmp;
        tmp = tmp->next;
        free(p);
    }

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}