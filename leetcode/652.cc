#include <vector>


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
    bool CheckEqual(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr)
            return true;
        if (node1 == nullptr || node2 == nullptr)
            return false;

        if (node1->val != node2->val)
            return false;
        return CheckEqual(node1->left, node2->left) && CheckEqual(node1->right, node2->right);
    }

    vector<TreeNode*> FindDuplicate(TreeNode* cur, vector<TreeNode*>* visited_ptr) {
        if (cur == nullptr)
            return {};

        auto& visited = *visited_ptr;
        auto left_result = FindDuplicate(cur->left, visited_ptr);
        auto right_result = FindDuplicate(cur->right, visited_ptr);
        vector<TreeNode*> result(left_result);
        result.insert(result.back(), right_result.begin(), right_result.end());

        bool found = false;
        for (auto& v : visited) {
            if (!CheckEqual(v, cur))
                continue;
            found = true;

            bool r_found = false;
            for (auto& r : result) {
                if (!CheckEqual(r, cur))
                    continue;
                r_found = true;
                break;
            }
            if (!r_found)
                result.emplace_back(cur);
            break;
        }
        if (!found)
            visited.emplace_back(cur);
        return result;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> visited;
        return FindDuplicate(root, &visited);
    }
};
