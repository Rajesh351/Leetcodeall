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
private: 
    // Helper function 'f' for recursion
    void f(Node* &root, vector <int> &ans){
        if (root == NULL) return; // Agar root NULL hai toh return kar do

        for (auto child : root->children){ // Har child ke liye recursion
            f(child, ans);
            ans.push_back(child->val); // Child ka value add karo
        }
    }

public:
    vector<int> postorder(Node* root) {
        vector <int> ans;
        f(root, ans);
        if (root != NULL) ans.push_back(root->val); // Root ka value add karo agar root NULL nahi hai
        return ans;
    }
};