/*This is the code for judging whether the two trees are the same*/

#include <iostream>

using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;
    bool flag;
};

bool check(TNode *root, int e)
{
    if (root->flag)
    {
        if (e < root->data)
        {
            return check(root->left, e);
        }
        else if (e > root->data)
        {
            return check(root->right, e);
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (e == root->data)
        {
            root->flag = true;
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool judge(TNode *root, int n)
{
    int e;
    bool flag = true;

    cin >> e;
    if (e != root->data)
    {
        flag = false;
    }
    else
    {
        root->flag = true;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> e;
        if ((!check(root, e)) && flag)
        {
            flag = false;
        }
    }
    return flag;
}

void reset(TNode *root)
{
    if (root->left)
    {
        reset(root->left);
    }
    if (root->right)
    {
        reset(root->right);
    }
    root->flag = false;
}

void freeTree(TNode *root)
{
    if (root->left)
    {
        freeTree(root->left);
    }
    if (root->right)
    {
        freeTree(root->right);
    }
    delete root;
}

TNode *insert(TNode *root, int e)
{
    if (root == NULL)
    {
        root = new TNode;
        root->data = e;
        root->flag = false;
        root->left = root->right = NULL;
    }
    else
    {
        if (e < root->data)
        {
            root->left = insert(root->left, e);
        }
        else
        {
            root->right = insert(root->right, e);
        }
    }
    return root;
}

TNode *create(int n)
{
    TNode *root = NULL;
    int e;

    cin >> e;
    root = new TNode;
    root->data = e;
    root->flag = false;
    root->left = root->right = NULL;
    for (int i = 1; i < n; i++)
    {
        cin >> e;
        root = insert(root, e);
    }
    return root;
}

int main()
{
    int n, l;
    TNode *root;

    cin >> n;
    while (n)
    {
        cin >> l;
        root = create(n);
        for (int i = 0; i < l; i++)
        {
            if (judge(root, n))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            reset(root);
        }
        freeTree(root);
        cin >> n;
    }
    return 0;
}