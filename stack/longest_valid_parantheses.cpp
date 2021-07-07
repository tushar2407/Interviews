#include<bits/stdc++.h>
using namespace std;
int main()
{

    string s;
    cin>>s;
    stack<int> t;
    stack<pair<int,int>> prev;
    int ans =0, prev_ans = 0, last_ind = 0;
    bool flag = false;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            t.push(i);
        }
        else if(t.size())
        {
            if(prev.size() && prev.top().first<t.top())
            {
                prev_ans += i-t.top()+1;
            }
            else{
                while(prev.size() && prev.top().first>t.top())
                {
                    // cout<<prev.top().first<<" "<<t.top()<<endl;
                    prev_ans-=prev.top().second;
                    prev.pop();
                }
                prev_ans += i-t.top()+1;
            }
            prev.push({t.top(), i-t.top()+1});
            t.pop();
            ans = max(ans, prev_ans);
            flag = true;
        }
        else{
            flag = false;
            prev_ans = 0;

        }
    }
    cout<<ans<<endl;
    return 0;
}