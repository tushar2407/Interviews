/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // method 1
TreeNode* findPath(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root)
        return NULL;
    if(root==p || root==q)
        return root;

    TreeNode* left = findPath(root->left, p,q);
    TreeNode* right = findPath(root->right, p,q);
    
    if(right && left) return root;
    
    return (!left)?right:left;
}
//method 2 (BETTER) in time complexity
bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path)
{
    if(!root)
        return false;
    path.push_back(root);
    if(root==p)
        return true;
    if(
        (root->left && findPath(root->left, p, path)) || 
        (root->right && findPath(root->right,p,path))
    )
        return true;
    // remove the last added element which is the root as it does not lead to 'p' node
    path.pop_back();
    return false;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> p1,p2;
    findPath(root,p,p1);
    findPath(root,q,p2);
    int i;
    // find the first different element in both the paths
    for(i=0;i<p1.size()&&i<p2.size();i++)
    {
        if(p1[i]!=p2[i])
            break;
    }
    return p1[i-1];
}
