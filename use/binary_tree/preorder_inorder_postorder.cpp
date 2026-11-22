#include <iostream>
#include <cassert>
#include <sstream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

void testTraversals() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    assert(root->data == 1);
    assert(root->left->data == 2);
    assert(root->right->data == 3);

    TreeNode* single = new TreeNode(10);
    assert(single->left == nullptr);
    assert(single->right == nullptr);

    assert(root != nullptr);
    assert(single != nullptr);

    TreeNode* empty = nullptr;
    preorder(empty);
    inorder(empty);
    postorder(empty);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::cout << "Preorder: ";
    preorder(root);

    std::cout << "\nInorder: ";
    inorder(root);

    std::cout << "\nPostorder: ";
    postorder(root);

    std::cout << "\n";

    testTraversals();

    return 0;
}
