#include <iostream>
#include <cassert>
#include <algorithm>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int treeHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return 1 + std::max(leftHeight, rightHeight);
}

void testTreeHeight() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    assert(treeHeight(root) == 3);

    assert(treeHeight(nullptr) == 0);

    TreeNode* single = new TreeNode(10);
    assert(treeHeight(single) == 1);

    TreeNode* leftTree = new TreeNode(1);
    leftTree->left = new TreeNode(2);
    leftTree->left->left = new TreeNode(3);
    leftTree->left->left->left = new TreeNode(4);

    assert(treeHeight(leftTree) == 4);

    TreeNode* balanced = new TreeNode(1);
    balanced->left = new TreeNode(2);
    balanced->right = new TreeNode(3);
    balanced->left->left = new TreeNode(4);
    balanced->left->right = new TreeNode(5);
    balanced->right->left = new TreeNode(6);
    balanced->right->right = new TreeNode(7);

    assert(treeHeight(balanced) == 3);
}

int main() {
    testTreeHeight();

    return 0;
}
