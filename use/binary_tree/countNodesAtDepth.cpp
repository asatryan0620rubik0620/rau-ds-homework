#include <iostream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int countNodesAtDepth(TreeNode* root, int k) {
    if (root == nullptr || k <= 0) {
        return 0;
    }

    if (k == 1) {
        return 1;
    }

    return countNodesAtDepth(root->left, k- 1) + countNodesAtDepth(root->right, k - 1);
}

void testCountNodesAtDepth() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    assert(countNodesAtDepth(root, 1) == 1);
    assert(countNodesAtDepth(root, 2) == 2);
    assert(countNodesAtDepth(root, 3) == 2);
    assert(countNodesAtDepth(root, 4) == 0);

    assert(countNodesAtDepth(nullptr, 1) == 0);
    assert(countNodesAtDepth(root, 0) == 0);
    assert(countNodesAtDepth(root, -1) == 0);

    TreeNode* single = new TreeNode(10);

    assert(countNodesAtDepth(single, 1) == 1);
    assert(countNodesAtDepth(single, 2) == 0);

    TreeNode* leftTree = new TreeNode(1);
    leftTree->left = new TreeNode(2);
    leftTree->left->left = new TreeNode(3);
    leftTree->left->left->left = new TreeNode(4);

    assert(countNodesAtDepth(leftTree, 1) == 1);
    assert(countNodesAtDepth(leftTree, 2) == 1);
    assert(countNodesAtDepth(leftTree, 3) == 1);
    assert(countNodesAtDepth(leftTree, 4) == 1);
}

int main() {
    testCountNodesAtDepth();

    return 0;
}
