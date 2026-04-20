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
    map<TreeNode*, int> maxSum;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        
        // optimization
        if(maxSum[root]) return maxSum[root];

        int robNode = root->val;

        if(root->left) {
            robNode += dfs(root->left->left) + dfs(root->left->right);
        }
        if(root->right) {
            robNode += dfs(root->right->left) + dfs(root->right->right);
        }
        
        int notRobNode = dfs(root->left) + dfs(root->right);
        
        // optimization
        maxSum[root] = max(robNode, notRobNode);
        return maxSum[root];
    }

public:
    int rob(TreeNode* root) {
        return dfs(root);
    }
};