#include<bits/stdc++.h>
using namespace std;

// from in-built queue
/// costly push
struct Stack
{
    queue<int> q1, q2;
    int cur_size = 0;

    int top()
    {
        return q1.front();
    }
    void push(int val)
    {
        q2.push(val);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1=q2;
        q2=q;
        cur_size++;
    }
    void pop()
    {
        if(q1.empty())
            return ;
        q1.pop();
        cur_size--;

    }
    int size()
    {
        return cur_size;
    }
};
// fro inbuilt queue
// costly pop and top
struct Stack
{
    queue<int> q1, q2;
    int cur_size=0;

    int top()
    {
        if(q1.empty())
            return -1;
        
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front();

        q1.pop();

        q2.push(temp);

        queue<int> q = q1;
        q1 = q2;
        q2 = q;

        return temp;
    }
    void push(int val)
    {   
        q1.push(val);
        cur_size++;
    }
    void pop()
    {
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        cur_size--;
        queue<int> q = q1;
        q1=q2;
        q2=q;
    }
    int size()
    {
        return cur_size;
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
  
    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.push(5);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
  
    cout << "current size: " << s.size()
         << endl;
    return 0;
}