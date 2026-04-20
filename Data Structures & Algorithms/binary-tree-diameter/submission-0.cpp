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
private:
    int dfs(TreeNode* root, int &diameter) {
        if(!root) return 0;

        int lb_depth = dfs(root->left, diameter);
        int rb_depth = dfs(root->right, diameter);
        diameter = max(diameter, lb_depth + rb_depth);
        return 1 + max(lb_depth, rb_depth); 
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
       int diameter = 0;
       dfs(root, diameter);
       return diameter;
    }
};
