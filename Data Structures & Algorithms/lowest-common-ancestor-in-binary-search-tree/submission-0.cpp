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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while(curr) {
            // case 1: (left-subtree)
            if(p->val < curr->val && q->val < curr->val)
                curr = curr->left;
            // case 1: (right-subtree)
            else if(p->val > curr->val && q->val > curr->val)
                curr = curr->right;
            // case 3: (split OR (p || q equals root))
            else return curr;
        }
        return nullptr;
    }
};
