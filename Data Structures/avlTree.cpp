#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val, height;
    Node* left, *right;
    Node(int v)
    {
        this->val = v;
        left=right=NULL;
        height=1;
    }
};
int max(int a, int b)
{
    return (a>b)?a:b;
}
int height(Node* root)
{
    if(!root)
        return 0;
    return root->height;
}
Node* leftRotate(Node* y)
{
    Node* x = y->right;
    y->right = x->left;
    x->left = y;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

Node* rightRotate(Node *x)
{
    Node* y = x->left;
    x->left = y->right;
    y->right = x;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

int getBalance(Node* root)
{
    if(!root)
        return 0;
    return height(root->left)-height(root->right);
}
Node * insert(Node* root, int val)
{
    if(!root)
        return (new Node(val));
    
    if(val<root->val)
        root->left = insert(root->left, val);
    else if(val>root->val)
        root->right = insert(root->right, val);
    else 
        return root;
    
    root->height = max(height(root->left), height(root->right))+1;

    int balance = getBalance(root);

    if(balance>1 && val<root->left->val)
    {
        return rightRotate(root);
    }
    if(balance<-1 && val>root->right->val)
    {
        return leftRotate(root);
    }
    if(balance > 1 && val>root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && val<root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
Node * minValueNode(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
Node* deleteNode(Node* root, int val)
{
     
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
 
    // If the val to be deleted is smaller
    // than the root's val, then it lies
    // in left subtree
    if ( val < root->val )
        root->left = deleteNode(root->left, val);
 
    // If the val to be deleted is greater
    // than the root's val, then it lies
    // in right subtree
    else if( val > root->val )
        root->right = deleteNode(root->right, val);
 
    // if val is same as root's val, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            Node *temp = root->left ?
                         root->left :
                         root->right;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; // Copy the contents of
                           // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);
 
            // Copy the inorder successor's
            // data to this node
            root->val = temp->val;
 
            // Delete the inorder successor
            root->right = deleteNode(root->right,
                                     temp->val);
        }
    }
 
    // If the tree had only one node
    // then return
    if (root == NULL)
    return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));
 
    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced,
    // then there are 4 cases
 
    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
int maxValueNode(Node * root)
    {
        while(root->right !=NULL)
        {
            root = root->right;
        }
        return root->val;
    }
void solve(vector<int> nums, int k)
{
    vector<int> ans;
        Node* root = NULL;
        for(int i=0;i<k;i++)
        {
            root = insert(root, nums[i]);
        }
        
        // cout<<endl;
        ans.push_back(maxValueNode(root));
        for(int i=k;i<nums.size();i++)
        {
            // {-7,-8,7,5,7,1,6,0}
            // cout<<nums[i-k]<<endl;
            preOrder(root);
            cout<<endl;
            root = deleteNode(root, nums[i-k]);
            // cout<<i<<endl;
            root = insert(root, nums[i]);
            ans.push_back(maxValueNode(root));
        }
        cout<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        // return ans;
}
int main()
{

    Node *root = NULL;
     
    // /* Constructing tree given in
    // the above figure */
    // root = insert(root, 10);
    // root = insert(root, 20);
    // root = insert(root, 30);
    // root = insert(root, 40);
    // root = insert(root, 50);
    // root = insert(root, 25);
    
    // /* The constructed AVL Tree would be
    //         30
    //         / \
    //        20 40
    //        / \ \
    //       10 25 50
    // */
    // cout << "Preorder traversal of the "
    //         "constructed AVL tree is \n";
    // preOrder(root);


    // root = insert(root, 1);
    // root = insert(root, 3);
    // root = insert(root, -1);
    // root = insert(root, 0);
    // root = insert(root, 6);
    // root = insert(root, 11);
    // root = insert(root, -1);
    // root = insert(root, 1);
    // root = insert(root, 2);
 
    /* The constructed AVL Tree would be
            9
        / \
        1 10
        / \ \
    0 5 11
    / / \
    -1 2 6
    */
 
    // cout << "Preorder traversal of the "
    //         "constructed AVL tree is \n";
    // preOrder(root);
 
    // root = deleteNode(root, 1);
 
    // /* The AVL Tree after deletion of 10
    //         1
    //     / \
    //     0 9
    //     / / \
    // -1 5     11
    //     / \
    //     2 6
    // */
 
    // cout << "\nPreorder traversal after"
    //      << " deletion of 10 \n";
    // preOrder(root);

    solve({-7,-8,7,5,7,1,6,0}, 4);
    return 0;
}