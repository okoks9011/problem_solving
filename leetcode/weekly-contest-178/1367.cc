/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


using namespace std;


class Solution {
  public:
    bool isSubPathImpl(ListNode* head, TreeNode* root, bool started) {
        if (!head)
            return true;
        if (!root)
            return false;

        if (head->val == root->val) {
            if (isSubPathImpl(head->next, root->left, true))
                return true;
            if (isSubPathImpl(head->next, root->right, true))
                return true;
        }

        if (!started) {
            if (isSubPathImpl(head, root->left, false))
                return true;
            if (isSubPathImpl(head, root->right, false))
                return true;
        }

        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return isSubPathImpl(head, root, false);
    }
};
