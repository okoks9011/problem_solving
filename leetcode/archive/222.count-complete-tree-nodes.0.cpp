/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left_height = 1;
        auto cur = root->left;
        while (cur) {
            cur = cur->left;
            ++left_height;
        }

        int right_height = 1;
        cur = root->right;
        while (cur) {
            cur = cur->right;
            ++right_height;
        }

        if (left_height == right_height)
            return (1 << left_height) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
