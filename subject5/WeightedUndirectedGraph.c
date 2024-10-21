#include <stdio.h>
#include <stdlib.h>
#include "WeightedUndirectedGraph.h"
#define INF 9999999

// A utility function to create a new adjacency list node
Edge* newAdjListNode(int dest, int w)
{
    Edge *p;

	p = (Edge *)malloc(sizeof(Edge));
    p->endpoint = dest;
	p->weight = w;
    p->next = NULL;
    return p;
}

void printList(Edge *L)
{
	Edge *p;
	
	printf("[");
	for (p = L; p != NULL; p = p->next)
	{
		printf("%d (%d) %s", p->endpoint, p->weight, (p->next == NULL) ? "" : ", ");
	}
	printf("]\n");
}

Edge *insertAtList(int dest, Edge *L, int w)
{
	Edge *p, *q = NULL, *t;
	
	t = newAdjListNode(dest, w);
	
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
Graph *InsertEdge(Graph *g, int src, int dest, int w)
{
	g->firstedge[src] = insertAtList(dest, g->firstedge[src], w);
	g->firstedge[dest] = insertAtList(src, g->firstedge[dest], w);
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

void MinimumSpanningTree(Graph *g)
{
	int *vis;
	Edge *p;
	int ne, v;

	vis = (int *)calloc(g->n, sizeof(int));

	// the number of egde in minimum spanning tree will be
	// always less than (V -1), where V is number of vertices in
	// graph

	// choose 0th vertex and make it true
	vis[0] = 1;

	int x;  //  row number
	int y;  //  col number

	// print for edge and weight
	printf("Edge : Weight\n");

	for(ne = 0; ne < (g->n) - 1; ne++)
	{
    //For every vertex in the set S, find the all adjacent vertices
    // , calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    //choose another vertex nearest to selected vertex  at step 1.

		int min = INF;

		for (v = 0; v < g->n; v++) 
		{
			if (vis[v]) 
			{
				for (p=g->firstedge[v]; p != NULL; p=p->next)
				{
					if (vis[p->endpoint] == 0) 
					{
						if (p->weight < min) 
						{
							min = p->weight;
							x = v;
							y = p->endpoint;
						}
					}
				}
			}
		}
		printf("%d - %d : %d\n", x, y, min);
		vis[y] = 1;
  }
}