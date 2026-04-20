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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        TreeNode* prevNode;

        if(!root) return new TreeNode(val);
         
        while(curr) {
            prevNode = curr;
            // go down left subtree
            if(val < curr->val) curr = curr->left;
            // go down right subtree
            else curr = curr->right;
        }
        if(val < prevNode->val) 
            prevNode->left = new TreeNode(val);
        else prevNode->right = new TreeNode(val);
        return root;
    }
};