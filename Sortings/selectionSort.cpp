#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& a, int n)
{
    int i, j, min_idx;
    
    cout<<"State after every iteration :\n";
    
    for(i=0;i<n;i++)
    {
        min_idx = i;
        for(j=i+1;j<n;j++)
            if(a[min_idx]>a[j])
                min_idx = j;
        
        swap(a[i], a[min_idx]);
    
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
}
int main()
{

    vector<int> a = {5,4,2,1,3};
    int n =5;
    
    selectionSort(a, n);
    
    cout<<"Final state:\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}