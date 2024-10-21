#include <stdio.h>
#include <stdlib.h>
#include "UnDirectedGraph.h"

Edge* newAdjListNode(int dest)
{
    Edge *p;

	p = (Edge *)malloc(sizeof(Edge));
    p->endpoint = dest;
    p->next = NULL;
    return p;
}

void printList(Edge *L)
{
	Edge *p;
	
	printf("[");
	for (p = L; p != NULL; p = p->next)
	{
		printf("%d%s", p->endpoint, (p->next == NULL) ? "" : ", ");
	}
	printf("]\n");
}

Edge *insertAtList(int dest, Edge *L)
{
	Edge *p, *q = NULL, *t;
	
	t = newAdjListNode(dest);
	
	for (p = L; p != NULL; q = p, p = p->next) ;
	if (q == NULL)
	{
		L = t;
	}
	else
	{
		q->next = t;
	}
	return L;
}

// Creates a graph of n vertices
Graph *Initialize(int n)
{
	int i;
    Graph* g;
	
	g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
 
    // Initialize each adjacency list as empty by
    
    for (i = 0; i < n; i++)
        g->firstedge[i] = NULL;
 
    return g;
}
 
// Adds an edge to a directed graph
Graph *InsertEdge(Graph *g, int src, int dest)
{
	g->firstedge[src] = insertAtList(dest, g->firstedge[src]);
	g->firstedge[dest] = insertAtList(src, g->firstedge[dest]);
	return g;
}
 
// Print the adjacency list representation of graph
void ShowGraph(Graph* g)
{
    int i;
	
    for (i = 0; i < g->n; i++)
	{
		printf("%d --> ", i);
        printList(g->firstedge[i]);
    }
}

int f(Graph *g, int *vis, int *path, int *k, Vertex v, Vertex u)
{
	Edge *p;
	
	vis[v] = 1;
	path[(*k)++] = v;
	if (v == u)
		return 1;
	for (p=g->firstedge[v]; p != NULL; p=p->next)
	{
		if (vis[p->endpoint] == 0)
		{
			return f(g, vis, path, k, p->endpoint, u);
		}
	}
	return 0;
}

void SimplePathCheck(Graph *g, Vertex v, Vertex u)
{
	int *vis;
	int *path;
	int k = 0;
	
	vis = (int *)calloc(g->n, sizeof(int));
	path = (int *)calloc(g->n, sizeof(int));
	if (f(g, vis, path, &k, v, u))
	{
		int i;
		printf("Simple Path does exist\n");
		for (i = 0; i < k; i++)
			printf("%d ", path[i]);
	}
	else
		printf("Simple Path does not exist\n");
}