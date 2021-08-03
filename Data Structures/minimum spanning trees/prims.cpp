#include<bits/stdc++.h>
using namespace std;

int getMinKey(vector<int>& key, vector<bool>& mstSet)
{
    int mine = INT_MAX, min_index=-1;
    for(int i=0;i<key.size();i++)
    {
        if(!mstSet[i] && key[i]<mine)
        {
            mine = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(vector<vector<pair<int,int>>>& g, vector<int>& parent)
{
    for(int i=1;i<g.size();i++)
    {
        cout<<parent[i]<<" "<<i<<endl;
    }
}
// O(V^2) time
// can pbe improved to (E+LogV) using Fibonacci heaps
void prims(vector<vector<pair<int,int>>>& g)
{
    
    vector<int> parent(g.size());

    vector<bool> mstSet(g.size());

    vector<int> key(g.size(), INT_MAX);

    key[0] = 0;
    parent[0]=-1;

    for(int i=0;i<g.size();i++)
    {
        int k = getMinKey(key, mstSet);

        mstSet[k] = true;

        for(int j=0;j<g[k].size();j++)
        {
            if(!mstSet[g[k][j].first] && g[k][j].second < key[g[k][j].first])
            {
                parent[g[k][j].first] = k;
                key[g[k][j].first] = g[k][j].second;
            }
        }
    }

    printMST(g, parent);
}

int main()
{
    vector<vector<pair<int,int>>> graph = { { {1,2}, {3,6} }, 
                                            { {0,2}, {3,3}, {4,8}, {5,5} }, 
                                            { {1,3}, {5,7} }, 
                                            { {0,6}, {1,8}, {5,9} }, 
                                            { {1,5}, {2,7}, {3,9}} 
                                        }; 
  
    // Print the solution 
    prims(graph); 


    return 0;
}