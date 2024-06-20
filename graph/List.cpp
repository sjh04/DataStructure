#include <iostream>

using namespace std;

#define MAX_VERTEX_NUM 100
#define INFINITY 65535

typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode *PtrToENode;
typedef struct GNode *PtrToGNode;

struct ENode
{
    Vertex V1, V2;
    WeightType Weight;
};

typedef PtrToENode Edge;

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};

typedef struct VNode
{
    PtrToAdjVNode FirstEdge;
    DataType Data;
} AdjList[MAX_VERTEX_NUM];

struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum)
{
    Vertex V;
    LGraph Graph;

    Graph = new GNode;
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for (V = 0; V < Graph->Nv; V++)
    {
        Graph->G[V].FirstEdge = NULL;
    }

    return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;

    NewNode = new AdjVNode;
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;

    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    NewNode = new AdjVNode;
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;

    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
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
        cin >> Graph->G[V].Data;
    }

    return Graph;
}

void PrintGraph(LGraph Graph)
{
    PtrToAdjVNode p;
    for (int i = 0; i < Graph->Nv; i++)
    {
        for (int j = 0; j < Graph->Nv; j++)
        {
            p = Graph->G[i].FirstEdge;
            bool found = false;
            while (p)
            {
                if (p->AdjV == j)
                {
                    cout << p->Weight << " ";
                    found = true;
                    break;
                }
                p = p->Next;
            }
            if (!found)
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    LGraph Graph = BuildGraph();
    PrintGraph(Graph);
    return 0;
}