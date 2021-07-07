#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(vector<vector<int>>& graph, vector<bool>& visited, int ind, stack<int>& s)
{
    visited[ind]=true;
    for(const auto &i : graph[ind])
    {
        if(!visited[i])
            topologicalSortUtil(graph, visited, i, s);
    }
    s.push(ind);
}
void topologicalSort(vector<vector<int>>& graph)
{
    stack<int> s;
    vector<bool> visited(graph.size());

    for(int i=0;i<graph.size();i++)
    {
        if(!visited[i])
            topologicalSortUtil(graph, visited, i, s);
    }

    // pop and print sideways 
}