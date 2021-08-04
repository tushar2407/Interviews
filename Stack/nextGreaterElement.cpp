#include<bits/stdc++.h>
using namespace std;
// gives the next greater "element"
vector<long long> nextLargerElement(vector<long long> arr, int n){
    // Your code here
    stack<long long> st;
    st.push(0);
    vector<long long> res(n, -1);
    for(int i=1;i<n;i++)
    {
        while(!st.empty() && arr[i]>arr[st.top()])
        {
            res[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
// tells how many "indexes" later is the next greater element
vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> stack;
    stack.push_back(0);
    vector<int> res(T.size(), 0 );
    int stack_size = 1;
    for(int i=1;i<T.size(); i++)
    {
        while(stack_size>0 && T[i] > T[stack[stack_size-1]])
        {
            res[stack[stack_size-1]] = i - stack[stack_size-1];
            stack.erase(stack.begin() + stack_size-1);
            stack_size--;
        }
        stack.push_back(i);
        stack_size++;
    }
    return res;
}
int main()
{
    vector<int> a = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(a);
    for(int i=0;i<a.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
/*
    Given a list of daily temperatures T, return a list such that, 
    for each day in the input, tells you how many days you would have to wait 
    until a warmer temperature. If there is no future day for which this is possible, 
    put 0 instead.

    For example, given the list of temperatures 
    T = [73, 74, 75, 71, 69, 72, 76, 73], 
    your output should be
    [1, 1, 4, 2, 1, 1, 0, 0].

*/