#include <iostream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void mirrorTree(TreeNode* root){
    if (root == nullptr) {
        return;
    }

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}


void testMirrorTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    mirrorTree(root);

    assert(root->data == 1);
    assert(root->left->data == 3);
    assert(root->right->data == 2);
    assert(root->right->right->data == 4);

    TreeNode* single = new TreeNode(10);
    mirrorTree(single);

    assert(single->left == nullptr);
    assert(single->right == nullptr);

    mirrorTree(nullptr);

    TreeNode* leftTree = new TreeNode(1);
    leftTree->left = new TreeNode(2);
    leftTree->left->left = new TreeNode(3);

    mirrorTree(leftTree);

    assert(leftTree->right->data == 2);
    assert(leftTree->right->right->data == 3);
    assert(leftTree->left == nullptr);
    mirrorTree(leftTree);

    assert(leftTree->left->data == 2);
    assert(leftTree->left->left->data == 3);
    assert(leftTree->right == nullptr);
}

int main() {
    testMirrorTree();

    return 0;
}
