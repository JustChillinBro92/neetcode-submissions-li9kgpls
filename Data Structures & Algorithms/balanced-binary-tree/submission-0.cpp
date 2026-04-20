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
    int dfs(TreeNode* root, bool &balanced) {
        if(!balanced) return 0;
        if(!root) return 0;
        
        int lb_depth = dfs(root->left, balanced);
        int rb_depth = dfs(root->right, balanced);
        if(abs(lb_depth - rb_depth) > 1) balanced = false;
        return 1 + max(lb_depth, rb_depth);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        dfs(root, balanced);
        return balanced;
    }
};
