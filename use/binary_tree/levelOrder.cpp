#include <iostream>
#include <cassert>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void levelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        std::cout << current->data << " ";
        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void testLevelOrder() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    assert(root->data == 1);
    assert(root->left->data == 2);
    assert(root->right->data == 3);
    assert(root->left->left->data == 4);
    assert(root->left->right->data == 5);

    TreeNode* single = new TreeNode(10);
    assert(single->left == nullptr);
    assert(single->right == nullptr);
    TreeNode* empty = nullptr;
    levelOrder(empty);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Level order: ";
    levelOrder(root);

    std::cout << "\n";

    testLevelOrder();

    return 0;
}
