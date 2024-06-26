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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBSTRecursive(nums, 0, nums.size() - 1);
    }

    TreeNode* constructBSTRecursive(vector<int>& nums, int left, int right) {
        if(left > right)
            return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = constructBSTRecursive(nums, left, mid - 1);
        node->right = constructBSTRecursive(nums, mid + 1, right);
        return node;
    }
    void raj(TreeNode *root,vector<int>&v)
    {
        if(root==NULL) return;
        raj(root->left,v);
        v.push_back(root->val);
        raj(root->right,v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        raj(root,v);
        return sortedArrayToBST(v);
        
    }
};