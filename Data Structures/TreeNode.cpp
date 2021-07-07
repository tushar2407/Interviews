#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 int main()
 {
    TreeNode* temp = new TreeNode(10);
    TreeNode* root(temp);
    // string x = string(s.begin(), s.end());
    cout<<root->val<<endl;
    return 0;
 }