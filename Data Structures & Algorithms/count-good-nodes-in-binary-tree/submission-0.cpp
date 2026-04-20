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
    int dfs(TreeNode* node, int maxSoFar) {
        if(!node) return 0;

        if(node->val >= maxSoFar) {
            return 1
               + dfs(node->left, max(maxSoFar, node->val))
               + dfs(node->right, max(maxSoFar, node->val));
        }

        return
            dfs(node->left, max(maxSoFar, node->val))
          + dfs(node->right, max(maxSoFar, node->val));
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
