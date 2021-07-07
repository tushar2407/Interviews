#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define vll vector<ll>
#define pll pair<ll, ll>
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
    while(j>i && s[j]==s[i]){i++;j--;}
    if(i==j || i>j) return 1;
    return 0;
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
vector<vector<ll>> dp;
ll find(string &s1, string &s2, ll ind1, ll ind2)
{
    if(ind1 == 0 || ind2 ==0 )
        return dp[ind1][ind2]=0;
    
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s1[ind1-1]==s2[ind2-1])
        return dp[ind1][ind2] = 1 + find(s1,s2,ind1-1,ind2-1);

    return dp[ind1][ind2] = max(find(s1,s2,ind1-1,ind2),find(s1,s2,ind1,ind2-1));
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
        string s1,s2;
        cin>>s1>>s2;
        dp.resize(s1.length()+1, vector<ll>(s2.length()+1,-1));
        for(int i=0;i<s1.length();i++)
            dp[i][0] = 0;
        for(int i=0;i<s2.length();i++)
            dp[0][i]=0;
        // Recursive memoized
        find(s1,s2,s1.length(),s2.length());
        
        // DP
        // for(int i=0;i<=s1.length();i++)
        // {
        //     for(int j=0;j<=s2.length();j++)
        //     {
        //         if(i==0 || j==0)
        //             dp[i][j] = 0;
        //         else if(s1[i-1]==s2[j-1])
        //             dp[i][j] = dp[i-1][j-1]+1;
        //         else
        //             dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
        //     }
        // }
        
        string s;
        ll i = s1.length(), j = s2.length();
        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                s+=s1[i-1];
                i--,j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
                    i--;
            else
                j--;
        }
        reverse(s.begin(), s.end());
        cout<<s<<endl;
    }
    return 0;
}