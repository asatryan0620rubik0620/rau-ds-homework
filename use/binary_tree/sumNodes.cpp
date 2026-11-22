#include <iostream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int sumNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

void testSumNodes() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    assert(sumNodes(root) == 10);

    assert(sumNodes(nullptr) == 0);

    TreeNode* single = new TreeNode(10);
    assert(sumNodes(single) == 10);

    TreeNode* balanced = new TreeNode(1);
    balanced->left = new TreeNode(2);
    balanced->right = new TreeNode(3);
    balanced->left->left = new TreeNode(4);
    balanced->left->right = new TreeNode(5);

    assert(sumNodes(balanced) == 15);

    TreeNode* negative = new TreeNode(-5);
    negative->left = new TreeNode(-3);
    negative->right = new TreeNode(2);

    assert(sumNodes(negative) == -6);

    TreeNode* duplicates = new TreeNode(5);
    duplicates->left = new TreeNode(5);
    duplicates->right = new TreeNode(5);

    assert(sumNodes(duplicates) == 15);
}

int main() {
    testSumNodes();

    return 0;
}
