#include <utility>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    void normalize(TreeNode* cur) {
        if (cur == nullptr)
            return;
        normalize(cur->left);
        normalize(cur->right);

        if (cur->left != nullptr && cur->right != nullptr) {
            if (cur->left->val > cur->right->val)
                swap(cur->left, cur->right);
        } else if (cur->right != nullptr) {
            swap(cur->left, cur->right);
        }
    }

    bool equal(TreeNode* cur1, TreeNode* cur2) {
        if (cur1 == nullptr && cur2 == nullptr)
            return true;
        if (cur1 == nullptr || cur2 == nullptr)
            return false;
        if (cur1->val != cur2->val)
            return false;

        return equal(cur1->left, cur2->left) && equal(cur1->right, cur2->right);
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        normalize(root1);
        normalize(root2);

        return equal(root1, root2);
    }
};
