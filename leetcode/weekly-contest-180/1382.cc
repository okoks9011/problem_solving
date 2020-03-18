/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>


using namespace std;


class Solution {
  public:
    void collectNodes(TreeNode* cur, vector<int>* values_ptr) {
        if (cur == nullptr)
            return;

        collectNodes(cur->left, values_ptr);
        values_ptr->emplace_back(cur->val);
        collectNodes(cur->right, values_ptr);
    }

    TreeNode* createBST(const vector<int>& values) {
        if (values.empty())
            return nullptr;
        int root_idx = values.size() / 2;

        TreeNode* result = new TreeNode(values[root_idx]);
        TreeNode* left = createBST({values.begin(), values.begin()+root_idx});
        TreeNode* right = createBST({values.begin()+root_idx+1, values.end()});

        result->left = left;
        result->right = right;
        return result;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        collectNodes(root, &values);

        return createBST(values);
    }
};
