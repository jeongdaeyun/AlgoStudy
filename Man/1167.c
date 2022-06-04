#include <stdio.h>
#include <stdlib.h>

int V, visited[100001], diameter = 0;

typedef struct nodes{
    int n;
    int c;
    struct nodes *link;
}nodes;

nodes *farthestNode;

void DFS(nodes *node, int cost, nodes *graph){
    if(node == NULL) return;
    if (visited[node->n]) return;
    visited[node->n] = 1;
    if(diameter < cost){
        diameter = cost;
        farthestNode = node;
    }

    nodes *tmp = (nodes*)malloc(sizeof(nodes));
    tmp = node;
    while(tmp != NULL){
        if(tmp->link != NULL) DFS(&graph[tmp->link->n], cost+tmp->link->c, graph);
        tmp = tmp->link;
    }
}

int main(void){
    scanf("%d", &V);
    V++;
    nodes graph[V];
    for (int i = 1; i < V; i++){
        int node;
        nodes *temp = (nodes*)malloc(sizeof(nodes));
        scanf("%d", &node);
        temp = &graph[node];
        graph[node].n = node;
        graph[node].c = 0;
        graph[node].link = NULL;
        while(1){
            int node2, cost;
            scanf("%d", &node2);
            if (node2 == -1) break;
            scanf("%d", &cost);
            nodes *tmp = (nodes*)malloc(sizeof(nodes));
            tmp->c = cost;
            tmp->n = node2;
            tmp->link = NULL;
            temp->link = tmp;
            temp = tmp;
        }
    }
    
    for(int i = 0; i < V; i++) visited[i] = 0;
    DFS(&graph[1], 0, graph);
    for(int i = 0; i < V; i++) visited[i] = 0;
    diameter = 0;
    DFS(farthestNode, 0, graph);
    printf("%d\n", diameter);
    return 0;
}