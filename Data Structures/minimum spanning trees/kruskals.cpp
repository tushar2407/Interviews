#include<bits/stdc++.h>
using namespace std;
struct subset
{
    int parent;
    int rank;
};
struct Edge {
    int src, dest, weight;
};
int find(vector<subset> &subsets, int i)
{
    if(subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(vector<subset>& subsets, int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if(subsets[xroot].rank<subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank>subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
bool cmp(const Edge& a, const Edge& b)
{
    return a.weight<b.weight;
}

void kruskal(vector<Edge>& graph, int n)
{
    int V = n;
    vector<Edge> result(n);
    int e = 0;
    int i = 0;

    sort(graph.begin(), graph.end(), cmp);

    vector<subset> subsets(V);

    for(int v=0;v<V;v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while(e < V-1 && i<graph.size())
    {
        Edge temp = graph[i++];
        int x = find(subsets, temp.src);
        int y = find(subsets, temp.dest);

        if(x!=y)
        {
            result[e++] = temp;
            Union(subsets, x, y);
        }
    }

    // now result stores the min spanning tree

}


int main()
{


    return 0;
}