#include <stdio.h>
#include <stdlib.h>
#include "WeightedUndirectedGraph.h"

int main()
{
    int n;
    Graph *g;
	scanf("%d", &n);
	
	g = Initialize(n);
	while (1)
	{
		Vertex x, y;
		int w;
		
		scanf("%d-%d-%d", &x, &y, &w);
		if (x < 0)
			break;
		g = InsertEdge(g, x, y, w);
	}
  
	printf("\nShowGraph\n");
    ShowGraph(g);
	MinimumSpanningTree(g);
 
    return 0;
}