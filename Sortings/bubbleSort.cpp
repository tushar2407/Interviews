#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& a, int n)
{
    int i,j, total_swaps = 0;
    for(i=0; i<n-1; i++)
    {
        int swaps = 0;
        
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
                swap(a[j], a[j+1]), swaps++;
        }
        
        cout<<"Swaps : "<<swaps<<endl;
        total_swaps+=swaps;
        
        // cout<<"Current State : \n";
        // for(int i=0;i<n;i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;    
    }
    cout<<"Total Swaps : "<<total_swaps<<endl;
}
int main()
{

    vector<int> a = {5,4,2,1,3};
    int n =5;
    bubbleSort(a, n);
    cout<<"Final state:\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}