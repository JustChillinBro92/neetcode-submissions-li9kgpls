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
    vector<int> t1, t2;
    
    void dfs(TreeNode *root, vector<int> &t) {
        if(!root) { 
            t.push_back(-1);
            return;
        }

        t.push_back(root->val);
        dfs(root->left, t);
        dfs(root->right, t);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, t1); dfs(q, t2);
        return t1 == t2;
    }
};
