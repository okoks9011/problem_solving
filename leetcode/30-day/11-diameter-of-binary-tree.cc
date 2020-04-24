/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Elem {
    int height = 0;
    int longest = 0;

    Elem(int h, int l) : height(h), longest(l) {}
};

class Solution {
public:
    Elem calPath(TreeNode* cur) {
        if (!cur)
            return {0, 0};
        auto left_e = calPath(cur->left);
        auto right_e = calPath(cur->right);

        int height = max(left_e.height, right_e.height) + 1;
        int longest = left_e.height + right_e.height;
        longest = max(longest, max(left_e.longest, right_e.longest));
        return {height, longest};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        auto e = calPath(root);
        return e.longest;
    }
};
