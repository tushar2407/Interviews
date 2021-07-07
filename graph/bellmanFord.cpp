int BellmanFord(int n, vector<vector<int>>& flights, int src, int dst, int k) {    
    vector<int> cur(n, INT_MAX);
    vector<int> prev(n, INT_MAX);
    
    cur[src] = 0;
    prev[src] = 0;
    for(int j=0;j<flights.size();j++)
        if(flights[j][0]==src){
            int v = flights[j][1];
            int wt = flights[j][2];
            prev[v] = min(prev[src]+wt, prev[v]);
            cur[v] = prev[v];
        }
    for(int i=2;i<=k+1;i++) // atmost k edges used
    {
        for(int j=0;j<n;j++)
            cur[j]=prev[j];
        for(int j=0;j<flights.size();j++)
        {
            int u = flights[j][0];
            int v = flights[j][1];
            int wt = flights[j][2];
            if(prev[u]!=INT_MAX)
                cur[v] = min(cur[v], prev[u]+wt);
        }
        prev = cur;
    }
    return (cur[dst]==INT_MAX)?-1:cur[dst];
}