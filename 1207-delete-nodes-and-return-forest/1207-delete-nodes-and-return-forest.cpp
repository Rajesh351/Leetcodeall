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
    TreeNode* solve(TreeNode* root, unordered_map<int, int>& mp, vector<TreeNode*>& ans) {
    if (root == NULL) return NULL;
    
    root->left = solve(root->left, mp, ans);
    root->right = solve(root->right, mp, ans);
    
    if (mp.find(root->val) != mp.end()) {
        if (root->left != NULL) ans.push_back(root->left);
        if (root->right != NULL) ans.push_back(root->right);
        return NULL;
    }
    
    return root;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    unordered_map<int, int> mp;
    for (auto a : to_delete) mp[a]++;
    
    vector<TreeNode*> ans;
    
    if (mp.find(root->val) == mp.end()) {
        ans.push_back(root); // Only add root if it's not in to_delete list
    }
    
    solve(root, mp, ans);
    
    return ans;
}
};