#include <iostream>

using namespace std;

#define MAX_VERTEX_NUM 100
#define INFINITY 65535

typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct GNode *PtrToGNode;
typedef struct ENode *PtrToENode;

struct ENode
{
    Vertex V1, V2;
    WeightType Weight;
};

typedef PtrToENode Edge;
typedef PtrToGNode MGraph;

struct GNode
{
    int Nv;
    int Ne;
    WeightType G[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    DataType Data[MAX_VERTEX_NUM];
};

MGraph CreateGraph(int VertexNum)
{
    Vertex V, W;
    MGraph Graph;

    Graph = new GNode;
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for (int i = 0; i < Graph->Nv; i++)
    {
        for (int j = 0; j < Graph->Nv; j++)
        {
            Graph->G[i][j] = INFINITY;
        }
    }

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    cin >> Nv;
    Graph = CreateGraph(Nv);

    cin >> Graph->Ne;
    if (Graph->Ne != 0)
    {
        E = new ENode;
        for (i = 0; i < Graph->Ne; i++)
        {
            cin >> E->V1 >> E->V2 >> E->Weight;
            InsertEdge(Graph, E);
        }
    }

    for (V = 0; V < Graph->Nv; V++)
    {
        cin >> Graph->Data[V];
    }

    return Graph;
}

int main()
{
    MGraph Graph = BuildGraph();
    return 0;
}
