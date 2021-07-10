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
 

int main()
{

    Node *root = NULL;
     
    /* Constructing tree given in
    the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
     
    /* The constructed AVL Tree would be
                30
            / \
            20 40
            / \ \
        10 25 50
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}