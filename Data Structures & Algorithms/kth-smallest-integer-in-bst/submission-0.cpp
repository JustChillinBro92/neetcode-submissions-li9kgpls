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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while(curr || !stk.empty()) {
            // traverse left subtree
            while(curr) {
                stk.push(curr);
                curr = curr->left;
            }

            // reached end of node (null)
            curr = stk.top();
            stk.pop();
            k -= 1;
            
            if(k == 0) return curr->val;

            // traverse right subtree
            curr = curr->right; 
        }
        return -1;
    }
};
