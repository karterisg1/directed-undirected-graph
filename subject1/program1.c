#include <stdio.h>
#include <stdlib.h>
#include "DirectedGraph.h"

int main()
{
    int n;
	Toporder T;
    Graph *g, *rg;
	scanf("%d", &n);
	
	g = Initialize(n);
	while (1)
	{
		Vertex x, y;
		
		scanf("%d-%d", &x, &y);
		if (x < 0)
			break;
		g = InsertEdge(g, x, y);
	}
  
	printf("\nShowGraph\n");
    ShowGraph(g);
	printf("\nDF_Traversal\n");
	DF_Traversal(g);
	printf("\nBreadthTopSort\n");
	BreadthTopSort(g, T);
	printf("\nShowReverseGraph\n");
	rg = GraphReverse(g);
	ShowGraph(rg);
	printf("\nStrongComponents\n");
	StrongComponents(g, rg);
 
    return 0;
}