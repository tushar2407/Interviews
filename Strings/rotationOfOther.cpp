#include<bits/stdc++.h>
using namespace std;

bool checkRotation(string s1, string s2)
{
    if(s1.size()!=s2.size())
        return false;
    
    queue<char> q1;
    for(auto&i:s1)
        q1.push(i);
    
    queue<char> q2;
    for(auto&i:s2)
        q2.push(i);
    
    if(q1==q2)
        return true;
    int k = s2.size();

    while(k--)
    {
        char t = q1.front();
        q1.pop();
        q1.push(t);
        if(q1==q2)
            return true;
    }
    return false;
}

int main()
{

    string s1="AACD",s2="ACDB";
    cout<<checkRotation(s1,s2)<<endl;
    return 0;
}