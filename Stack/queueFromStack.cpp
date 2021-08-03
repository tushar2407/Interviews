#include<bits/stdc++.h>
using namespace std;

stack<int> s1, s2;
void enQueue(int x)
{
    // Your Code
    
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    
    // stack<int> s= s1;
    // s1 = s2;
    // s2 = s;
}
int deQueue()
{
        // Your Code  
        if(s1.empty())
            return -1;
        int q = s1.top();
        s1.pop();
        return q;
}
int main()
{

    return 0;
}