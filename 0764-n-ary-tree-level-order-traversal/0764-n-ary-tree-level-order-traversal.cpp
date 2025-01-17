/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(!root) return v;
        queue<Node*> pq;
        
        pq.push(root);
        while (!pq.empty()) {
            vector<int> a;
            int n = pq.size();
            for (int i = 0; i < n; i++) {
                Node* temp = pq.front();
                if(temp!=NULL)
                a.push_back(temp->val);
                pq.pop();
                for (Node* child : temp->children) {
                    if (child!=NULL)
                        pq.push(child);
                }
            }
            v.push_back(a);
        }
        return v;
    }
};