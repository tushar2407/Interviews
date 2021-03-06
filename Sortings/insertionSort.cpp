#include<bits/stdc++.h>
using namespace std;

// iterative
void insertionSort(vector<int>& a, int n)
{
    int i,key,j;
    for( i = 1; i < n ; i++ )    
    {
        key = a[i];
        j = i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1] = a[j];
            j--;
        }
        
        cout<<"Swaps : "<<i-j-1<<endl;
        
        a[ j + 1 ] = key;
    }
} 

// recursive
void insertionSortRec(vector<int>& a, int n)
{
    if(n==1)
        return;

    insertionSortRec(a, n-1);

    int key = a[n-1];
    int j = n-2;

    while(j>=0 && a[j]>key)
    {
        a[j+1]=a[j];
        j--;
    }

    cout<<"Swaps: "<<n-1-j-1<<endl;

    a[j+1] = key;
}
int main()
{
    vector<int> a = {5,4,2,1,3};
    int n =5;
    
    // iterative
    // insertionSort(a, n);

    // recursive
    insertionSortRec(a,n);
    
    cout<<"Final state:\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}