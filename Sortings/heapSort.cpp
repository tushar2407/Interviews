#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& a, int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && a[largest]<a[l])
        largest = l;
    
    if(r<n && a[largest]<a[r])
        largest = r;

    if(largest!=i)
    {
        swap(a[i], a[largest]);

        heapify(a, n, largest);
    }
}

void heapSort(vector<int>& a, int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    
    for(int i=n-1;i>0;i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}
int main()
{

    
    vector<int> a = {5,4,2,1,3};
    int n =5;
    
    heapSort(a, n);
    
    cout<<"Final state:\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}