// O(V^2)
int findMinDist(vector<int>& dist, vector<bool>& visited)
{
    int minInd = -1, minDis = INT_MAX;
    for(int i=0;i<dist.size();i++)
    {
        if(!visited[dist[i]] && minDis >= dist[i])
        {
            minDis = dist[i];
            minInd = i;   
        }
    }
    return minInd;
}

vector<int> dijkstra(vector<vector<pair<int,int>>>& graph)
{
    vector<bool> visited(graph.size());
    vector<int> dist(graph.size());
    for(int i=0;i<graph.size();i++)
        dist[i]=INT_MAX;
    dist[0] = 0;

    for(int i=0;i<n-1;i++)
    {
        int u = findMinDist(dist, visited);

        visited[u] = true;

        for(int j=0;j<graph[u].size();j++)
        {
            if(!visited[graph[u][j]]] && dist[u]!=INT_MAX)
                dist[graph[u][j]].first = min(dist[graph[u][j].first], dist[u]+graph[u][j].second);
        }
    }
    return dist;
}
// O(ElogV)
int dijkstra(vector<vector<pair<int,int>>>& graph, int src, int dest)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> pq;
    vector<int> dist(graph.size(), INT_MAX);
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty())
    {

        pair<int,int> temp = pq.top();
        pq.pop();

        int  u = temp.second;

        for(const auto &it : graph[u])
        {
            int v = it.first;
            int w = it.second;
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[dest];
}