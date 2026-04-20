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
    vector<int> arr;

    void dfs(TreeNode* node) {
        if(!node) return;

        dfs(node->left);
        arr.push_back(node->val);
        dfs(node->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        for(auto &num : arr) cout << num << ", ";
        return arr[k-1];
    }
};
