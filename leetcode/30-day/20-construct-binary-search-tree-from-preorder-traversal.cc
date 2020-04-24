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
    TreeNode* bstFromPreorder(const vector<int>& preorder) {
        if (preorder.empty())
            return NULL;

        TreeNode* result = new TreeNode(preorder[0]);
        auto greater_it = find_if(preorder.begin(), preorder.end(), [&](int v){ return v > preorder[0]; });
        result->left = bstFromPreorder({preorder.begin()+1, greater_it});
        result->right = bstFromPreorder({greater_it, preorder.end()});
        return result;
    }
};
