#include "graph_bfs_dfs.h"

Vertex VertexInitialize(int value) {
  Vertex v = (Vertex)malloc(sizeof(Vertex));
  v->value = value;
  return v;
}

Graph GraphInitialize(int V) {
  Graph G = (Graph)malloc(sizeof(Graph));
  G->V = V;
  G->E = 0;
  G->adj = (Vertex **)malloc(V * sizeof(Vertex *));
  for (int i = 0; i < G->V; i++) {
    G->adj[i] = (Vertex *)malloc(G->E * sizeof(Vertex));
    for (int j = 0; j < 1; j++) {
      G->adj[i][j] = VertexInitialize(0);
    }
  }
  return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2) {
  G->E++;
  for (int i = 0; i < G->V; i++) {
    G->adj[i] =
        (Vertex *)realloc(G->adj[i], G->E * sizeof(Vertex));
    if (i == v1->value) {
      G->adj[i][G->E - 1] = VertexInitialize(1);
    } else if (i == v2->value) {
      G->adj[i][G->E - 1] = VertexInitialize(-1);
    } else {
      G->adj[i][G->E - 1] = VertexInitialize(0);
    }
  }
}

void ImprimeGraph(Graph G) {
  for (int i = 0; i < G->V; i++) {
    printf("[%2d]-> ", i);
    for (int j = 0; j < G->E; j++) {
      if (G->adj[i][j]->value == 1) {
        printf("[ 1]");
      } else if (G->adj[i][j]->value == -1) {
        printf("[-1]");
      } else {
        printf("[  ]");
      }
    }
    printf("\n");
  }
}