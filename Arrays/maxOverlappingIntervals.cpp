#include<bits/stdc++.h>
using namespace std;

int overlap(vector<pair<int,int>>& v)
{
    vector<pair<int,char>> data;
    for(int i=0;i<v.size();i++)
    {
        data.push_back({v[i].first,'x'});
        data.push_back({v[i].second,'y'});
    }
    sort(data.begin(), data.end());
    int ans = 0, count = 0;
    for(int i=0;i<data.size();i++)
    {
        (data[i].second=='x')?count++:count--;
        ans = max(ans, count);
    }
    return ans;
}
int main()
{

    vector<pair<int, int> > v
        = { { 1, 2 }, { 2, 4 }, { 3, 6 } };
    cout<<overlap(v)<<endl;

    return 0;
}