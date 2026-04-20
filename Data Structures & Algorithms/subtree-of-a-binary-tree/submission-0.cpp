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
    bool sameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queue1, queue2;;
        queue1.push(p);
        queue2.push(q);

        while(!queue1.empty() && !queue2.empty()) {
            TreeNode* current1 = queue1.front();
            TreeNode* current2 = queue2.front();
            queue1.pop();
            queue2.pop();

            // if both null then skip current iteration
            if(!current1 && !current2) continue;

            // either any one null node OR values unequal then not same tree
            if(!current1 || !current2 || current1->val != current2->val) 
                return false;

            queue1.push(current1->left);
            queue1.push(current1->right);
            queue2.push(current2->left);
            queue2.push(current2->right);
        }

        // both queue must be empty for same tree
        return queue1.empty() && queue2.empty();
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> stk;
        stk.push(root);

        TreeNode* node;
        while(!stk.empty()) {
            node = stk.top();
            stk.pop();

            if(node) {
                if(sameTree(node, subRoot)) return true;

                if(node->left) stk.push(node->left);
                if(node->right) stk.push(node->right);
            }
        }
        return false;
    }
};
