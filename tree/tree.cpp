#include <iostream>

using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;
};

TNode *createTree(int e)
{
    TNode *newNode = new TNode;
    newNode->data = e;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TNode *insertTree(TNode *root, int e)
{
    if (root == NULL)
    {
        return createTree(e);
    }
    if (e < root->data)
    {
        root->left = insertTree(root->left, e);
    }
    else
    {
        root->right = insertTree(root->right, e);
    }
    return root;
}

void PreOrder(TNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(TNode *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(TNode *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    TNode *root = NULL;
    root = insertTree(root, 10);
    root = insertTree(root, 5);
    root = insertTree(root, 15);
    root = insertTree(root, 3);
    root = insertTree(root, 7);
    root = insertTree(root, 12);
    root = insertTree(root, 18);
    cout << "PreOrder: ";
    PreOrder(root);
    cout << endl;
    cout << "InOrder: ";
    InOrder(root);
    cout << endl;
    cout << "PostOrder: ";
    PostOrder(root);
    cout << endl;
    return 0;
}