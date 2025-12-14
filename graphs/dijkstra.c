#include <stdio.h>
#include <stdbool.h>

/*
The Dijkstra Algorithm:
Dijkstra(G, w, s):
    for all vertice v in G:
        set dist[v] = inf
        set paren[v] = null
    dist[s] = 0
    Q = priority_queue({v, dist[v]} for all v)
    while Q is not empty:
        u = get_min(Q)
        for each neighbor v of u:
            if dist[u] + w(u, v) < dist[v]:
                dist[v] = dist[u] + w(u, v)
                update(Q, {v, dist[v]})
                paren[v] = u
            remove(Q, u)
    return(dist, paren)
*/

#define MAX_VERTICES 1000
#define INF 999999

// Graph Adjacency Matrix Implementation
int graph[MAX_VERTICES][MAX_VERTICES];
int vertices = 0;

void init_graph(int v);
void join_vertices(int v1, int v2);

// Priority Queue using binary heap
// Main Data: Tuple (dist[v], v), organized by value of dist[v]
typedef struct pq_entry {
    int dist_v;
    int v;
} pq_entry;

typedef struct pq {
    pq_entry heap[MAX_VERTICES];
    int size;
} pq;

void pq_insert(int v, int dist_v);
int pq_get_min(pq q);
void pq_update(int v, int dist_v);
void pq_remove(int v);
bool pq_is_empty(pq q);

// Dijkstra Implemntation
void dijkstra(int source) {
    int dist[vertices];
    int paren[vertices];

    for(int i = 0; i < vertices; i++) {
        dist[i] = INF;
        paren[i] = -1;
    }

    dist[source] = 0;

    pq queue;
    for(int i = 0; i < vertices; i++) {
        pq_insert(i, dist[i]);
    }

    while (!pq_is_empty(queue)) {
        int v = pq_get_min(queue);
        
    }
}

int main() {
    printf("Hello World!\n");
    return 0;
}
