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
    TreeNode *sum(TreeNode *root, int &sum1)
    {
        if(root==NULL) return NULL;
         sum(root->right,sum1);
        sum1+=root->val;
        root->val=sum1;
          sum(root->left,sum1);
          return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum1=0;
         sum(root,sum1);
         return root;
    }
};