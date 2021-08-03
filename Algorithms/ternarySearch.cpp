#include<bits/stdc++.h>
using namespace std;

int ternarySearch(vector<int>& a, int l, int r, int k)
{
    while(l<=r)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        if(a[mid1]==k)
            return mid1;
        if(a[mid2]==k)
            return mid2;
        if(k<a[mid1])
            r=mid1-1;
        else if(k>a[mid2])
            l = mid2+1;
        else
        {
            l = mid1+1;
            r=mid2-1;
        }
    }
    return -1;
}
int main()
{
    vector<int> a = {1,2,3,4,5,6,8};
    cout<<ternarySearch(a, 0, a.size()-1, 1);
    return 0;
}