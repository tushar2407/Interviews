#include<bits/stdc++.h>
#define ll long long
using namespace std;

void merge(vector<int>& a, int low, int mid, int high)
{
    int l = mid-low+1;
    int r = high-mid;
    
    vector<int> larr, rarr;
    
    for(int i=0;i<l;i++)
        larr.push_back(a[low+i]);
    
    for(int i=0;i<r;i++)
        rarr.push_back(a[mid+i+1]);
    
    int i=0, j=0, k=low;
    int swaps = 0;

    while(i<l && j<r)
    {
        if(larr[i]>rarr[j]){
            swaps+=l-i;
            a[k++] = rarr[j++];
        }
        else
            a[k++] = larr[i++];
    }
    while(i<l)
        a[k++]=larr[i++];
    
    while(j<r)
        a[k++]=rarr[j++];
    cout<<"SWAPS: "<<swaps<<endl;
    // dbg(swaps, a, i, j, k);
}

void mergeSort(vector<int>& a, int low, int high)
{
    if(low<high)
    {

        int mid = (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a, low, mid, high);
        // merge(a, mid+1, high);
    }
}

int main()
{

    
    vector<int> a = {0, 3, 4};
    int n =3;
    
    mergeSort(a, 0, n-1);
    
    cout<<"Final state:\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}