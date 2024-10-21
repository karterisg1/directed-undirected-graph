#include <stdio.h>
#include <stdlib.h>
#include "UnDirectedGraph.h"

int main()
{
    int n, u, v;
    Graph *g;
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
	printf("\nSimplePathCheck\n");
	printf("Enter 2 nodes: ");
	scanf("%d%d", &v, &u);
	SimplePathCheck(g, v, u);
    return 0;
}