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
   bool ans=false;
    bool solve(TreeNode *root,int k,unordered_map<int,int>&mp)
    {
        if(root==NULL) return true;
        if(mp.find(root->val)!=mp.end())
        {
            ans=true;
            return false;
        }
        if(ans==true) false;
        mp[k-root->val]++;
        solve(root->left,k,mp);
        if(ans==true) return false;
        solve(root->right,k,mp);
        return true;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mp;
        solve(root,k,mp);
        return ans;
    }
};