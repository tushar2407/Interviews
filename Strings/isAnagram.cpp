#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2, int len1, int len2)
{
    if(len1 == len2){
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 != s2) return false;        
        return true;
    }        
    return false;
}
int main()
{
    string s1 = "ddddddddg";
    string s2 = "dgggggggg";
    cout<<isAnagram(s1,s2,s1.length(), s2.length())<<endl;
    return 0;
}