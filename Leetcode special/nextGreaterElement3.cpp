#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(s.length()==1)
            return -1;
        char prev = *(s.end()-1);
        char smallest = prev;
        vector<char> st;
        st.push_back(prev);
        int i=s.length()-2;
        bool flag = false;
        while(i>=0 && !flag)
        {
            if(s[i]<prev)
            {
                flag = true;
                sort(st.begin(), st.end(), greater());
                auto temp = st.begin();
                smallest = st[0];
                for(int j=1;j<st.size();j++)
                {
                    if(st[j]>s[i] && st[j]<smallest){
                        smallest = st[j];
                        temp = st.begin()+j;
                    }
                }
                st.erase(temp);
                st.push_back(s[i]);
                break;
            }
            prev = s[i];
            st.push_back(s[i]);
            i--;
        }
        if(!flag)
            return -1;
        
        string ans = string(s.begin(), s.begin()+i);
        ans+=smallest;

        sort(st.begin(), st.end());
        for(auto&i:st)
        {
            ans+=i;
        }
        
        long limit = stol(ans);
        if(limit <=pow(2,31)-1)
            return stoi(ans);
        else return -1;
    }
};

/**
 * 
 * Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

    Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

    Input: n = 12
        Output: 21
 * 
 * 
 * 
 * 
 * **/