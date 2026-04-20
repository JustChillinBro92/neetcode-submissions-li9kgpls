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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1}); 
        int maxDepth = 0;

        pair<TreeNode*, int> current;
        while(!stack.empty()) {
            current = stack.top();
            stack.pop();
            
            TreeNode* node = current.first;
            int depth = current.second;

            if(node) {
                maxDepth = max(depth, maxDepth);
                if(node->left) stack.push({node->left, depth+1});
                if(node->right) stack.push({node->right, depth+1});
            }
        }

        return maxDepth;
    }
};
