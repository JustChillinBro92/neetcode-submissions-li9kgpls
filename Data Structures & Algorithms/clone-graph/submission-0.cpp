/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    map<Node*, Node*> oldToCopy;

    Node* dfs(Node* node) {
        // if neighbor needed already computed before
        // return the copy node corresponding to the og node
        if(oldToCopy.count(node))
            return oldToCopy[node];
        
        Node* copy = new Node(node->val);
        oldToCopy[node] = copy;

        for(Node* n : node->neighbors) {
            copy->neighbors.push_back(dfs(n));
        }

        return copy;
    }

public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        return dfs(node);
    }
};
