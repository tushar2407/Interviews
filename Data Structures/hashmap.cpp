#include<bits/stdc++.h>
using namespace std;

class Hash
{
    int buckets;
    vector<list<pair<int,int>>> l;
    public :
    Hash(int v)
    {
        buckets = v;
        l.resize(v);
    }
    int hashfunction(int x)
    {
        return x%buckets;
    }
    void insert(int key, int value )
    {
        int index = hashfunction(key);
        l[index].push_back({key, value});
    }
    bool get(int key)
    {
        int idx = hashfunction(key);
        for(auto &i: l[idx] )
        {
            if(i.first==key)
                return true;
        }
        return false;
    }
    void del(int key)
    {
        int idx = hashfunction(key);

        auto i = l[idx].begin();
        for(;i!=l[idx].end();i++)
        {
            if((*i).first == key)
                break;
        }

        if(i!=l[idx].end())
            l[idx].erase(i);
    }
    void display()
    {
        for(int i=0;i<buckets;i++)
        {
            cout<<i<<" ";
            for(auto&j : l[i])
                cout<<"-->{"<<j.first<<","<<j.second<<"}";
            cout<<endl;
        }
    }
};
int main()
{
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);
  
    Hash h(7);
    for (int i = 0; i < n; i++) 
        h.insert(a[i], i);  
    
    h.del(12);
    
    h.display();

    return 0;
}