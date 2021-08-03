#include<bits/stdc++.h>
using namespace std;

// O(n) extra space
bool cyclicUtil(vector<vector<int>>& graph, vector<bool>& visited, int ind, unordered_set<int>& temp)
{
    visited[ind] = true;
    temp.insert(ind);
    bool ans = false;
    for(int i=0;i<graph[ind].size();i++)
    {
        if(!visited[graph[ind][i]]){
            ans = ans || cyclicUtil(graph, visited, graph[ind][i], temp);
        }
        else if(temp.find(graph[ind][i]) != temp.end())
            return true;
    }
    
    temp.erase(ind);
    return ans;
}
bool isCyclic(vector<vector<int>>& graph, int n)
{
    vector<bool> visited(n);
    unordered_set<int> temp;
    int ans = false;
    for(int i=0;i<n;i++)
        if(!visited[i])
            ans = ans || cyclicUtil(graph, visited, i, temp);
    return ans;
}
// No extra space
bool isNotcyclicUtil(vector<vector<int>>& graph, vector<int>& visited, int ind)
{
    if(visited[ind])
        return visited[ind]==2; // is black or not
 
    visited[ind] = 1; // gray

    for(const auto & i:graph[ind])
    {
        if(visited[ind]==2)
            continue;
        if(visited[i]==1 || !isNotcyclicUtil(graph, visited, i)){
            return false;
        }
    }
    
    visited[ind]=2;
    return true;
}