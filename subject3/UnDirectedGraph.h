#define MAXVERTEX 50

typedef int Vertex;
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
void SimplePathCheck(Graph *g, Vertex v, Vertex u);