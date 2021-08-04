#include<bits/stdc++.h>
using namespace std;

bool representsBST(vector<int>& a)
{
    stack<int> st;
    int root = INT_MIN;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<root)
            return false;
        while(!st.empty() && st.top()<a[i])
        {
            root = st.top();
            st.pop();
        }
        st.push(a[i]);
    }
    return true;
}
int main()
{

    vector<int> pre1= {40, 30, 35, 80, 100};
    // int n = sizeof(pre1)/sizeof(pre1[0]);
    representsBST(pre1)? cout << "true\n":
                              cout << "false\n";
 
    vector<int> pre2 = {40, 30, 35, 20, 80, 100};
    // n = sizeof(pre2)/sizeof(pre2[0]);
    representsBST(pre2)? cout << "true\n":
                              cout << "false\n";
 
    return 0;
}