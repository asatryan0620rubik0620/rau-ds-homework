#include <iostream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};


int countLeaves(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

void testCountLeaves() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    assert(countLeaves(root) == 3);

    assert(countLeaves(nullptr) == 0);

    TreeNode* single = new TreeNode(10);
    assert(countLeaves(single) == 1);

    TreeNode* leftTree = new TreeNode(1);
    leftTree->left = new TreeNode(2);
    leftTree->left->left = new TreeNode(3);
    assert(countLeaves(leftTree) == 1);

    TreeNode* balanced = new TreeNode(1);
    balanced->left = new TreeNode(2);
    balanced->right = new TreeNode(3);
    balanced->left->left = new TreeNode(4);
    balanced->left->right = new TreeNode(5);
    balanced->right->left = new TreeNode(6);
    balanced->right->right = new TreeNode(7);

    assert(countLeaves(balanced) == 4);

    TreeNode* duplicates = new TreeNode(5);
    duplicates->left = new TreeNode(5);
    duplicates->right = new TreeNode(5);

    assert(countLeaves(duplicates) == 2);
}

int main() {
    testCountLeaves();


    return 0;
}
