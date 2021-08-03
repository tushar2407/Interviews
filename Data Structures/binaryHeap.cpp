#include<bits/stdc++.h>
using namespace std;

struct MinHeap
{
    int size = 0;
    int capacity = 11;
    vector<int> a;
    MinHeap()
    {
        a.resize(11);
    }
};
int getMin(MinHeap* m)
{
    return m->a[0];
}
int parent(MinHeap* m, int i)
{
    return (i-1)/2;
}
void insertKey(MinHeap* m, int k)
{
    if(m->size==m->capacity){return;}
    m->size++;
    int i = m->size-1;
    m->a[i]=k;

    while(i!=0 && m->a[parent(m,i)] > m->a[i])
    {
        swap(m->a[parent(m,i)], m->a[i]);
        i = parent(m,i);
    }
}

void decreaseKey(MinHeap* m, int i, int new_val)
{
    m->a[i] = new_val;
    while(i!=0 && m->a[parent(m,i)]>m->a[i])
    {
        swap(m->a[parent(m,i)], m->a[i]);
        i=parent(m,i);
    }
}
int left(int i)
{
    return (i+1)/2;
}
int right(int i)
{
    return (i+2)/2;
}
void minHeapify(MinHeap* m, int i)
{
    int l =left(i);
    int r = right(i);
    int smallest = i;

    if(l<m->size && m->a[l]<m->a[smallest])
        smallest = l;
    if(r<m->size && m->a[r]<m->a[smallest])
        smallest = r;

    if(smallest!=i)
    {
        swap(m->a[smallest], m->a[i]);
        minHeapify(m, smallest);
    }
}
int extractMin(MinHeap* m)
{
    if(m->size==0)
        return -1;
    if(m->size==1)
    {
        m->size--;
        return m->a[0];
    }

    int root = m->a[0];
    m->a[0] = m->a[m->size-1];
    m->size--;
    minHeapify(m, 0);

    return root;
}
void deleteKey(MinHeap* m, int i)
{
    decreaseKey(m, i, INT_MIN);
    extractMin(m);
}
int main()
{
    MinHeap* h = new MinHeap();
    // cout<<"SADFSdf"<<endl;
    insertKey(h, 3);
    // cout<<h->size<<endl;
    insertKey(h,2);
    // cout<<h->size<<endl;
    deleteKey(h,1);
    // cout<<h->size<<endl;
    insertKey(h,15);
    // cout<<h->size<<endl;
    insertKey(h,5);
    // cout<<h->size<<endl;
    insertKey(h,4);
    // cout<<h->size<<endl;
    insertKey(h,45);
    // cout<<h->size<<endl;
    cout << extractMin(h) << " ";
    cout << getMin(h) << " ";
    decreaseKey(h, 2, 1);
    cout << getMin(h);
    
    // return 0;


    return 0;
}