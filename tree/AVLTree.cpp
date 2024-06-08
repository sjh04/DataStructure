#include <iostream>

using namespace std;

struct AVLNode {
    int data;
    int height;
    AVLNode* left;
    AVLNode* right;
};

int Max(int a, int b) {
    return a > b ? a : b;
}

int GetHeight(AVLNode* root) {
    if (root == NULL) {
        return -1;
    }
    return root->height;
}

AVLNode* SingleLeftRotation(AVLNode* A) {
    AVLNode* B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    B->height = Max(GetHeight(B->left), A->height) + 1;
    return B;
}

AVLNode* SingleRightRotation(AVLNode* A) {
    AVLNode* B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    B->height = Max(A->height, GetHeight(B->right)) + 1;
    return B;
}

AVLNode* DoubleLeftRightRotation(AVLNode* A) {
    A->left = SingleRightRotation(A->left);
    return SingleLeftRotation(A);
}

AVLNode* DoubleRightLeftRotation(AVLNode* A) {
    A->right = SingleLeftRotation(A->right);
    return SingleRightRotation(A);
}

AVLNode* Insert(AVLNode* root, int data) {
    if (root == NULL) {
        root = new AVLNode();
        root->data = data;
        root->height = 0;
        root->left = root->right = NULL;
    } else if (data < root->data) {
        root->left = Insert(root->left, data);
        if (GetHeight(root->left) - GetHeight(root->right) == 2) {
            if (data < root->left->data) {
                root = SingleLeftRotation(root);
            } else {
                root = DoubleLeftRightRotation(root);
            }
        }
    } else if (data > root->data) {
        root->right = Insert(root->right, data);
        if (GetHeight(root->right) - GetHeight(root->left) == 2) {
            if (data > root->right->data) {
                root = SingleRightRotation(root);
            } else {
                root = DoubleRightLeftRotation(root);
            }
        }
    }
    root->height = Max(GetHeight(root->left), GetHeight(root->right)) + 1;
    return root;
}

void printH(AVLNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " " << (GetHeight(root->right) - GetHeight(root->left)) << endl;
    printH(root->left);
    printH(root->right);
}

int main() {
    AVLNode* root = NULL;
    root = Insert(root, 3);
    root = Insert(root, 2);
    root = Insert(root, 1);
    root = Insert(root, 4);
    root = Insert(root, 5);
    root = Insert(root, 5);
    root = Insert(root, 6);
    root = Insert(root, 7);
    root = Insert(root, 16);
    root = Insert(root, 15);
    root = Insert(root, 14);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 25);
    printH(root);
    return 0;
}