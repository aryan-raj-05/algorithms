#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 32
#define GROWTH_FACTOR 2

typedef struct entry {
    int key;
    int value;
} entry;

typedef struct map {
    entry* store;
    char* is_occupied;
    int number_of_keys;    // = 3
    int buckets;           // = 4
} map;

static void rehash(map* m) {
    
}

void initMap(map* m) {
    m->store = (entry*)malloc(INITIAL_SIZE * sizeof(entry));
    m->is_occupied = (char*)malloc(INITIAL_SIZE * sizeof(char));
    if (!m->store || !m->is_occupied) {
        fprintf(stderr, "Memory Allocation Failed!\n");
        exit(1);
    }
    memset(m->store, 0, INITIAL_SIZE * sizeof(entry));
    memset(m->is_occupied, 0, INITIAL_SIZE * sizeof(char));
    m->buckets = INITIAL_SIZE;
    m->number_of_keys = 0;
}

void insert(map* m, int key, int value) {
    
}

int get(map* m, int key) {
    return 0;
}

void deleteKey(map* m, int key) {

}

void deleteMap(map* m) {
    free(m->store);
    free(m->is_occupied);
    m->store = NULL;
    m->is_occupied = NULL;
    m->buckets = 0;
    m->number_of_keys = 0;
}

int main() {
    printf("hello, world!\n");
    return 0;
}