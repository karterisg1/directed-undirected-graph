#include <stdio.h>
#include <stdlib.h>
#include "QueueInterface.h"
#include "StackInterface.h"
#include "DirectedGraph.h"

int state[MAXVERTEX];
int time;
int d[MAXVERTEX];

// A utility function to create a new adjacency list node
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
 
// Adds an edge to an undirected graph
Graph *InsertEdge(Graph *g, int src, int dest)
{
	g->firstedge[src] = insertAtList(dest, g->firstedge[src]);
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

void DFS(Graph *g, int v)
{
	Edge *p;
	
	time++;
	d[v] = time;
	state[v] = visited;

	for (p = g->firstedge[v]; p != NULL; p = p->next)
	{
		if (state[p->endpoint] == initial)
		{
			printf("\n(%d,%d) - Tree edge\n", v, p->endpoint);
			DFS(g, p->endpoint);
		}
		else if (state[p->endpoint] == visited)
		{
			printf("\n(%d,%d) - Back edge\n", v, p->endpoint);
		}
		else if(d[v] < d[p->endpoint])
		{
			printf("\n(%d,%d) - Forward edge\n", v, p->endpoint);
		}
		else
		{
			printf("\n(%d,%d) - Cross edge\n", v, p->endpoint);
		}
	}
	state[v] = finished;
}

void DF_Traversal(Graph *g)
{
	int v;

	for(v=0; v<g->n; v++)
		state[v] = initial;

	DFS(g, 0);
	for(v=0; v<g->n; v++)
	{
		if(state[v] == initial)
			DFS(g, v);
	}
	printf("\n");
}

void BreadthTopSort(Graph *g, Toporder T)
{
	int pred[MAXVERTEX];  /* number of predecessors of each vertex */

	Queue Q;
	Vertex v, succ;
	Edge *p;
	int place;
	int i;

	/* initialize all the predecessor counts to 0  */
	for (v=0; v < g->n; v++)
		pred[v]=0;

	/* increase the predecessor count for each vertex that is a successor of another one */
	for (v=0; v < g->n; v++)
		for (p=g->firstedge[v]; p != NULL; p=p->next)
			pred[p->endpoint]++;

	/* initialize a queue */
	InitializeQueue(&Q);

	/* place all vertices with no predecessors into the queue */
	for (v=0; v < g->n; v++)
		if (pred[v]==0)
		{
			Insert(v, &Q);
		}
	/* start the breadth-first traversal */
	place=-1;
	while (!Empty(&Q)) 
	{
		/* visit v by placing it into the topological order */
		Remove(&Q, &v);
		place++;
		T[place]=v;

		/* traverse the list of successors of v */
		for (p=g->firstedge[v]; p != NULL; p=p->next)
		{
		   /* reduce the predecessor count for each successor */
		   succ=p->endpoint;
		   pred[succ]--;
		   if (pred[succ]==0)
			 /* succ has no further predecessors, so it is ready to process */
			 Insert(succ, &Q);
		}
	}
	for (i = 0; i <= place; i++)
		printf("It is %d\n", T[i]);
}

Graph *GraphReverse(Graph *g)
{
	Graph *rg;
	Edge *p;
	int v;
	
	rg = Initialize(g->n);
	
	for(v = 0; v < g->n; v++)
	{
		for (p=g->firstedge[v]; p != NULL; p=p->next)
		{
			rg = InsertEdge(rg, p->endpoint, v);
		}
	}
	return rg;
}

// A recursive function to print DFS starting from v
void dfs_recursive(Graph *g, int *vis, int v)
{
	Edge *p;
	vis[v] = 1;
	printf("%d ", v);
	for (p=g->firstedge[v]; p != NULL; p=p->next)
	{
		if (!vis[p->endpoint])
		{
			dfs_recursive(g, vis, p->endpoint);
		}
	}
}
	
// Fuction to fill the stack
void fillOrder(Graph *g, int v, int *vis, Stack *stack)
{
	Edge *p;
	
	vis[v] = 1;
	for (p=g->firstedge[v]; p != NULL; p=p->next)
	{
		if (!vis[p->endpoint])
		{
			fillOrder(g, p->endpoint, vis, stack);
		}
	}
	Push(v, stack);
}

void StrongComponents(Graph *g, Graph *rg)
{
	Stack stack;
	InitializeStack(&stack);
	int v;

	// Mark all the vertices as not visited (For first DFS)
	int *vis = calloc(g->n, sizeof(int));

	// Fill vertices in stack according to their finishing
	// times
	for (v = 0; v < g->n; v++)
		if (vis[v] == 0)
			fillOrder(g, v, vis, &stack);

	// Mark all the vertices as not visited (For second DFS)
	for (v = 0; v < g->n; v++)
		vis[v] = 0;

	// Now process all vertices in order defined by Stack
	while (!IsEmpty(&stack))
	{
		// Pop a vertex from stack
		Pop(&stack, &v);

		// Print Strongly connected component of the popped vertex
		if (vis[v] == 0)
		{
			dfs_recursive(rg, vis, v);
			putchar('\n');
		}
	}
}