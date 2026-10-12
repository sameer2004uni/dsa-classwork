#include <iostream>
#include <vector>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
TreeNode* arrayToBinaryTree(vector<int>& arr, int i) {
    if (i >= arr.size()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    root->left = arrayToBinaryTree(arr, 2 * i + 1);
    root->right = arrayToBinaryTree(arr, 2 * i + 2);

    return root;
}
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, -1, 6};
    TreeNode* root = arrayToBinaryTree(arr, 0);
    cout << "Inorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    return 0;
}
