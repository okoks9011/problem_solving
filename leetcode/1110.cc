#include <vector>
#include <unordered_set>
#include <algorithm>


using namespace std;


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
    bool isNodeDeleted(TreeNode* cur, bool is_root,
                       const vector<int>& to_delete, vector<TreeNode*>* result_ptr) {
        if (cur == nullptr)
            return true;

        auto it = find(to_delete.begin(), to_delete.end(), cur->val);
        bool delete_cur = it != to_delete.end();
        if (is_root && !delete_cur)
            result_ptr->emplace_back(cur);

        if (isNodeDeleted(cur->left, delete_cur, to_delete, result_ptr))
            cur->left = nullptr;
        if (isNodeDeleted(cur->right, delete_cur, to_delete, result_ptr))
            cur->right = nullptr;
        return delete_cur;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        isNodeDeleted(root, true, to_delete, &result);

        return result;
    }
};
