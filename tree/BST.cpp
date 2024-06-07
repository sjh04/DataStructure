#include <iostream>

using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;
};

TNode *insertTree(TNode *root, int e) {
    if (root == NULL) {
        root = new TNode;
        root->data = e;
        root->left = NULL;
        root->right = NULL;
    } 
    else if (e < root->data) {
        root->left = insertTree(root->left, e);
    } 
    else {
        root->right = insertTree(root->right, e);
    }
    return root;
}

TNode *find(TNode *root, int e) {
    while (root) {
        if (root->data > e) {
            root = root->left;
        }
        else if (root->data < e) {
            root = root->right;
        }
        else {
            return root;
        }
    }
    return NULL;
}

TNode *findMin(TNode *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

TNode *findMax(TNode *root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}

TNode *deleteTree(TNode *root, int e) {
    if (root == NULL) {
        return NULL;
    }
    else {
        if (root->data > e) {
            root->left = deleteTree(root->left, e);
        }
        else if (root->data < e) {
            root->right = deleteTree(root->right, e);
        }
        else {
            if (root->left && root->right) {
                TNode *temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteTree(root->right, temp->data);
            }
            else {
                TNode *temp = root;
                if (root->left == NULL) {
                    root = root->right;
                }
                else if (root->right == NULL) {
                    root = root->left;
                }
                delete temp;
            }
        }
    }
    return root;
}

void inorder(TNode *root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    TNode *root = NULL;
    root = insertTree(root, 5);
    root = insertTree(root, 3);
    root = insertTree(root, 7);
    root = insertTree(root, 2);
    root = insertTree(root, 4);
    root = insertTree(root, 6);
    root = insertTree(root, 8);
    inorder(root);
    cout << endl;
    root = deleteTree(root, 5);
    inorder(root);
    cout << endl;
    return 0;
}