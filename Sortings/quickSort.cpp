#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int low, int high)
{
    int i = low-1;
    int pivot = high;
    for( int j = low; j<=high-1 ; j++)
    {
        if(a[j] < a[pivot])
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[pivot]);
    cout<<"SWAPS : "<<i+1-low+1<<endl;
    return i+1 ;
}

void quickSort(vector<int>& a, int low, int high)
{
    if(low<high)
    {
        int p = partition(a,low,high);
        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }
}

int main()
{

    vector<int> a = {5,4,2,1,3};
    int n =5;
    
    quickSort(a, 0, n-1);
    
    cout<<"Final state:\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}