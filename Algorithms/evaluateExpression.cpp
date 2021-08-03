#include <bits/stdc++.h>
using namespace std;


/*

Problem Statement: You are given an expression which contains ( , ) , numbers , + , -  
  e.g 1-(10-50)+8. 
write a program to find the final output. 
 
Example Input:1-(10-50)+8 

Output: 49 

*/

int solve(string& s)
{
    int n = s.length();
    
    stack<char> st_str;
    stack<int> st_num;
    
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(' || s[i]=='+' || s[i]=='-')
        {
            st_str.push(s[i]);
        }
        else if(s[i]-48>=0 && s[i]-48<=9)
        {
            int temp = 0;
            while(i<n && s[i]-48>=0 && s[i]-48<=9)
            {
                temp*=10;
                temp+=(s[i]-48);
                i++;
            }
            i--;
            if(!st_str.empty() && st_str.top()=='-' && temp<0)
            {
                st_str.pop();
                temp*=(-1);
                st_str.push('+');
            }
            st_num.push(temp);
        }
        else
        {
            while(!st_str.empty() && st_str.top()!='(')
            {
                int a = st_num.top();
                st_num.pop();
                
                int b = 0;
                if(!st_num.empty())
                {
                    b = st_num.top();
                    st_num.pop();
                }
                
                int temp_result = 0;
                if(st_str.top()=='+')
                {
                    temp_result = b+a;
                }
                else
                {
                    temp_result = b-a;
                }
                
                st_str.pop();
                st_num.push(temp_result);
            }
            st_str.pop();
            if(!st_str.empty() && st_str.top()=='-' && st_num.top()<0)
            {
                int temp_result = st_num.top();
                st_num.pop();
                st_str.pop();
                temp_result*=(-1);
                st_str.push('+');
                st_num.push(temp_result);
            }
        }
    }
    while(st_num.size()>1 && !st_str.empty())
    {
        int a = st_num.top();
        st_num.pop();
        int b = 0;
        if(!st_num.empty())
        {
            b=st_num.top();
            st_num.pop();
        }
        
        int temp_result = 0;
        if(st_str.top()=='+')
        {
            temp_result = b+a;
        }
        else
        {
            temp_result = b-a;
        }
        st_str.pop();   
        
        if(!st_str.empty() && st_str.top()=='-' && temp_result<0)
        {
            st_str.pop();
            temp_result*=(-1);
            st_str.push('+');
        }
        st_num.push(temp_result);
    }
    
    if(!st_str.empty())
    {
        char sign = st_str.top();
        st_str.pop();
        if(sign=='-')
        {
            int temp_result = st_num.top();
            temp_result*=(-1);
            st_num.pop();
            st_num.push(temp_result);
        }
    }
    return st_num.top();
    
}
int main() {
	// your code goes here
	
	string s;
	cin>>s;
	
	cout<<solve(s);
	
	
	return 0;
}
