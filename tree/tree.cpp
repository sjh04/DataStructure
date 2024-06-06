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

void printTree(TNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main()
{
    TNode *root = NULL;
    root = insertTree(root, 5);
    root = insertTree(root, 3);
    root = insertTree(root, 7);
    root = insertTree(root, 2);
    root = insertTree(root, 4);
    root = insertTree(root, 6);
    root = insertTree(root, 8);
    printTree(root);
    return 0;
}