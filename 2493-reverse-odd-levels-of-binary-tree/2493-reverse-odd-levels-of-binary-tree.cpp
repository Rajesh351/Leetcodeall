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
    void slove(TreeNode *root,TreeNode *root1,int li)
    {
         if(root==NULL || root1==NULL) return ;
         if(li%2==0)
         swap(root->val,root1->val);
         slove(root->left,root1->right,li+1);
         slove(root->right,root1->left,li+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
 
     slove(root->left,root->right,0);
        return root;    
            
    }
};