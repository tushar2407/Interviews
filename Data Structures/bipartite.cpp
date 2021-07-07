#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(vector<vector<int>>& graph, int ind, vector<int>& visited)
{
    queue<int> q;
    q.push(ind);
    visited[ind] = 1;
        
    while(q.size())
    {
        int temp = q.front();
        q.pop();
        for(int i=0;i<graph[temp].size();i++)
        {
            if(!visited[graph[temp][i]])
            {
                visited[graph[temp][i]] = (visited[temp]==1)?-1:1;
                q.push(graph[temp][i]);
            }
            else if(visited[graph[temp][i]] == visited[temp])
                return false;
        }
    }
    return true;       
}