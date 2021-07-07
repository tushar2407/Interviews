class Solution {
public:
    map<int,string> a;
    
    vector<vector<string>> ans;
    int stoi(char a1)
    {
        return a1-48;
    }
        
    int helper(string c, int digit)
    {
        vector<string> temp;
        for(int i=0;i<a[digit].length();i++)
        {
            temp.push_back(c+a[digit][i]);
        }
        ans.push_back(temp);
        return ans.size()-1;
    }
    void helper(int digit, int ind)
    {
        int i=0,j=0;
        // i for digit string
        // j for ind length
        vector<string> temp;
        for(;j<ans[ind].size();j++)
        {
            for(i=0;i<a[digit].length();i++)
            {
                temp.push_back(ans[ind][j]+a[digit][i]);
            }
        }
        ans[ind]=temp;
    }
    vector<string> letterCombinations(string digits) {
//         vector<string> b;
//         for(int i=0;i<a[stoi(digits[0])].length();i++)    {
//             b.push_back(a[stoi(digits[0])][i]);
            
//         }
            a[2] = "abc";
        a[3] = "def";
        a[4] = "ghi";
        a[5] = "jkl";
        a[6] = "mno";
        a[7] = "pqrs";
        a[8] = "tuv";
        a[9] = "wxyz";
    
        helper("", stoi(digits[0]));
        for(int i=1;i<digits.length();i++)
        {
            for(int j=0;j<ans.size();j++)
                helper(stoi(digits[i]), j);
        }
        vector<string> finalAns;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
                finalAns.push_back(ans[i][j]);
        }
        return finalAns;
        
        
    }
};

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/