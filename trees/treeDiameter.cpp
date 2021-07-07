#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define vll vector<ll>
#define vb vector<bool>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
using namespace std;
// hash function to hash pairs in map
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
// heap comparator
struct greater1{
    bool operator()(const int& a,const int& b) const{
        return a>b;
    }
};
// DEBUG
void __print(int x) { cerr << x; }
void __print(ll x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
template<typename T, typename V>
void __print(const pair<T, V>& x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }
template<typename T>
void __print(const T& x) { int _ = 0; cerr << '{'; for (auto& i : x) cerr << (_++ ? "," : ""), __print(i); cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

bool isAnagram(string s1, string s2, int len1, int len2)
{
    if(len1 == len2){
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i < len1; i++) if (s1[i] != s2[i]) return false;        
        return true;
    }        
    return false;
}
int isPalindrome(string s, int i, int j){
    // i = start index
    // j = end index 
    while(i<j)
        if(s[i++]!=s[j--])
            return 0;
    return 1;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
ll min(ll a, ll b){ return (a>b)?b:a;}
ll max(ll a, ll b){ return (a<b)?b:a;}
struct Node{
    ll val;
    Node* right;
    Node* left;
    Node(int v)
    {
        val = v;
        right=NULL;
        left=NULL;
    }
};
ll d = 0;
ll solve(vvll& tree, ll cur, vb& visited, ll parent)
{
    if(!visited[cur])
    {
        visited[cur]=true;
        
        vll deg;
        bool flag = false;
        for(ll i=0;i<tree[cur].size();i++)
        {
            if(tree[cur][i]!=parent){
                flag = true;
                deg.pb(solve(tree, tree[cur][i], visited, cur));
            }
        }
        
        if(deg.size()){
            d = max(d, accumulate(deg.begin(), deg.end(), 0));
            // dbg(deg, cur);   
            return *max_element(deg.begin(), deg.end())+1;
        }
        return !flag;
    }
    return 0;
}
ll bfs(vvll& tree, ll i = 1, bool flag= false)
{
    vb visited(tree.size());
    queue<ll> q;
    vll dis(tree.size(), -1);
    dis[i] = 0;
    q.push((ll)i);
    visited[i]=true;
    while(!q.empty())
    {
        ll temp = q.front();
        q.pop();
        // visited[temp]=true;
        for(auto &it : tree[temp])
        {
            if(!visited[it])
            {
                dis[it] = dis[temp]+1;
                visited[it]=true;
                q.push(it);
            }
        }
    }
    pll ans = {0,i};
    for(ll i=1;i<tree.size();i++)
    {
        if(dis[i]>ans.f)
        {
            ans = {dis[i], i};
        }
    }
    dbg(dis, i);
    if(!flag)
        return ans.s;
    return ans.f;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r",stdout);
    // freopen("output.txt","w",stdin);
    ll t = 1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vvll tree(n+1);
        for(ll i=0;i<n-1;i++)
        {
            ll a,b;
            cin>>a>>b;
            tree[a].pb(b);
            tree[b].pb(a);
        }
        cout<<bfs(tree, bfs(tree), true);
        // cout<<d<<endl;
    }
    return 0;
}