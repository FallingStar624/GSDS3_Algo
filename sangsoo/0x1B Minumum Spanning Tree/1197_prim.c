#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100005

typedef struct {
    int weight;
    int v;
    struct Node* next;
} Node;

typedef struct {
    int weight;
    int u, v;
} Edge;

typedef struct {
    Edge data[MAX_NODES];
    int size;
} PriorityQueue;

Node* adj[MAX_NODES];
bool chk[MAX_NODES];
PriorityQueue pq;

void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->weight = w;
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void push(PriorityQueue* pq, Edge e) {
    int idx = ++pq->size;
    while (idx > 1 && pq->data[idx/2].weight > e.weight) {
        pq->data[idx] = pq->data[idx/2];
        idx /= 2;
    }
    pq->data[idx] = e;
}

Edge pop(PriorityQueue* pq) {
    int parent, child;
    Edge item, temp;

    item = pq->data[1];
    temp = pq->data[pq->size--];

    parent = 1;
    child = 2;

    while (child <= pq->size) {
        if (child < pq->size && pq->data[child].weight > pq->data[child+1].weight) {
            child++;
        }
        if (temp.weight <= pq->data[child].weight) break;

        pq->data[parent] = pq->data[child];
        parent = child;
        child *= 2;
    }

    pq->data[parent] = temp;
    return item;
}

int main(void) {
    int v, e;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);

        addEdge(a, b, cost);
        addEdge(b, a, cost);
    }

    chk[1] = true;
    int cnt = 0;
    int ans = 0;

    for (Node* node = adj[1]; node != NULL; node = node->next) {
        push(&pq, (Edge){node->weight, 1, node->v});
    }

    while (cnt < v - 1) {
        Edge top = pop(&pq);
        if (chk[top.v]) continue;

        ans += top.weight;
        chk[top.v] = true;
        cnt++;

        for (Node* node = adj[top.v]; node != NULL; node = node->next) {
            if (!chk[node->v]) {
                push(&pq, (Edge){node->weight, top.v, node->v});
            }
        }
    }

    printf("%d\n", ans);

    // Cleanup
    for (int i = 1; i <= v; i++) {
        Node* node = adj[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    return 0;
}
