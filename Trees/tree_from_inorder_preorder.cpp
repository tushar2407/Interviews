/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int preInd = 0;
    int search(vector<int>& in, int start, int end, int val)
    {
        for(int i=start;i<=end;i++)
            if(in[i]==val)
                return i;
        return -1;
    }    
        
    TreeNode* build(vector<int>& pre, vector<int>& in, int inSt, int inEnd)
    {
        if(inSt > inEnd)
            return NULL;
        
        TreeNode* a = new TreeNode(pre[preInd++]);
        if(inSt == inEnd)
            return a;
        
        int ind = search(in,inSt, inEnd,a->val);
        
        a->left = build(pre,in,inSt,ind-1);
        a->right = build(pre,in,ind+1,inEnd);
        return a;
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         return build(preorder,inorder,0,inorder.size()-1);
    }
};