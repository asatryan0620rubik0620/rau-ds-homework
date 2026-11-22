#include <iostream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool areIdentical(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }

    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    if (root1->data != root2->data) {
        return false;
    }

    return areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right);
}

void testAreIdentical() {
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    assert(areIdentical(tree1, tree2) == true);

    TreeNode* tree3 = new TreeNode(1);
    tree3->left = new TreeNode(2);
    tree3->right = new TreeNode(4);
    assert(areIdentical(tree1, tree3) == false);

    TreeNode* tree4 = new TreeNode(1);
    tree4->left = new TreeNode(2);

    assert(areIdentical(tree1, tree4) == false);
    assert(areIdentical(nullptr, nullptr) == true);
    assert(areIdentical(tree1, nullptr) == false);

    TreeNode* single1 = new TreeNode(5);
    TreeNode* single2 = new TreeNode(5);
    TreeNode* single3 = new TreeNode(10);

    assert(areIdentical(single1, single2) == true);
    assert(areIdentical(single1, single3) == false);

    TreeNode* duplicates1 = new TreeNode(5);
    duplicates1->left = new TreeNode(5);

    TreeNode* duplicates2 = new TreeNode(5);
    duplicates2->left = new TreeNode(5);
    assert(areIdentical(duplicates1, duplicates2) == true);
}

int main() {
    testAreIdentical();

    return 0;
}
