#include <iostream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}


void testCountNodes() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    assert(countNodes(root) == 4);

    assert(countNodes(nullptr) == 0);

    TreeNode* single = new TreeNode(10);
    assert(countNodes(single) == 1);

    TreeNode* duplicates = new TreeNode(5);
    duplicates->left = new TreeNode(5);
    duplicates->right = new TreeNode(5);

    assert(countNodes(duplicates) == 3);

    TreeNode* leftTree = new TreeNode(1);
    leftTree->left = new TreeNode(2);
    leftTree->left->left = new TreeNode(3);

    assert(countNodes(leftTree) == 3);
}

int main() {
    testCountNodes();

    return 0;
}
