#include<bits/stdc++.h>
#define ll long long int
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define LG 25
using namespace std;
// everything with is 1-indexed
// P[i][j] stores the 2^jth parent of ith node
// levels[i] stores the depth of the ith node from root
// size[i] stores the size of the subtree emerging from ith node
void dfs(ll child, ll par, vector<ll>& levels, vector<ll>& size, vector<vector<ll>>& P, vector<vector<ll>>& graph)
{
    size[child] = 1;
    levels[child]= levels[par]+1;
    P[child][0] = par;
    for(const auto &i : graph[child])
        if(i!=par)
        {
            dfs(i, child, levels, size, P, graph);
            size[child] += size[i];
        }
}

ll lca(ll u, ll v, vector<ll>& levels, vector<vector<ll>>& P )
{
    ll i, lg;
    
    if(levels[u]<levels[v]) swap(u,v);
    
    for(lg=0;(1<<lg)<=levels[u];lg++);
    
    lg--;

    for(i=lg; i>=0; i--){
        if (levels[u] - (1<<i) >= levels[v])
            u = P[u][i];
    }


    if (u == v) return u;

    for(i=lg; i>=0; i--)
    {
        if(P[u][i] != -1 && P[u][i]!=P[v][i])
            u = P[u][i], v = P[v][i];
    }
    
    return P[u][0];
}

ll get(ll u, ll dis, vector<ll>& levels, vector<vector<ll>>& P)
{
    dis = levels[u] - dis;
    ll i, lg=0;
    
    for(; (1<<lg) <= levels[u]; lg++);
    
    lg--;

    for(i=lg; i>=0; i--)
    {
        if(levels[u] - (1<<i) >=dis)
            u = P[u][i];
    }
    
    return u;
}
ll dis(ll u, ll v, vector<ll>& levels, vector<vector<ll>>& P)
{
    if(levels[u]<levels[v]) swap(u,v);

    ll w = lca(u,v, levels, P);

    return levels[u]+levels[v]-2*levels[w];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    vector<vector<ll>> P;
    vector<ll> levels, size;
	int i,n,q, m, j;
    int u, v;
    cin>>n;
    vector<vector<ll>> g(n+1);
    
    P.resize(n+1, vector<ll>(25));
    levels.resize(n+1);
    size.resize(n+1);

	fo(i, n-1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
	}
	fo(i, LG) 
        fo(j, n+1) 
            P[j][i] = -1;
	
    levels[0] = -1;
	
    dfs(1, 0, levels, size, P, g);
	
    for(i=1; i<LG; i++){
        Fo(j, 1, n+1)
            if (P[j][i-1] != -1)
                P[j][i] = P[P[j][i-1]][i-1];
	}
	return 0;
}