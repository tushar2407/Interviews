#include<bits/stdc++.h>
using namespace std;

// iterative
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

// recursive
void bubbleSortRec(vector<int>& a, int n)
{
    if(n==1)
        return;
    
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
            swap(a[i], a[i+1]);
    }

    bubbleSortRec(a,n-1);
}
int main()
{

    vector<int> a = {5,4,2,1,3};
    int n =5;
    
    // iterative
    // bubbleSort(a, n);
    
    // recursive
    bubbleSortRec(a, n);
    
    cout<<"Final state:\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}