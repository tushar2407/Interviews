class Solution {
public:
    vector<int> disjoint;
    bool unionOpt(int a, int b)
    {
        int c = find(a);
        int d = find(b);
        if(c!=d)
        {
            if(d>c)
                disjoint[c] = d;
            else
                disjoint[d]=c;
            return false;
        }
        return true;
    }
    int find(int a)
    {
        if(!disjoint[a])
            return a;
        while(disjoint[a])
        {
            a = disjoint[a];
            a=find(a);
        }
        return a;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        disjoint.resize(edges.size()+1, 0);
        for(int i=0;i<edges.size();i++)
        {
            if(unionOpt(edges[i][0], edges[i][1]))
                return edges[i];
        }
        return {0,0};
        
    }
};