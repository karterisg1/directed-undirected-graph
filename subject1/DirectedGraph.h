#define MAXVERTEX 50
#define initial 1
#define visited 2
#define finished 3

typedef int Vertex;
typedef Vertex Toporder[MAXVERTEX];
// A structure to represent an adjacency list node
typedef struct edge 
{
    Vertex endpoint;
    struct edge *next;
} Edge;
 
// A structure to represent a graph. A graph
// is an array of adjacency lists.

typedef struct graph 
{
    int n; // number of vertices in graph
    Edge *firstedge[MAXVERTEX];
} Graph;

Graph *Initialize(int n);
Graph *InsertEdge(Graph *g, int src, int dest);
void ShowGraph(Graph* g);
void DF_Traversal(Graph *g);
void BreadthTopSort(Graph *g, Toporder T);
Graph *GraphReverse(Graph *g);
void StrongComponents(Graph *g, Graph *rg);