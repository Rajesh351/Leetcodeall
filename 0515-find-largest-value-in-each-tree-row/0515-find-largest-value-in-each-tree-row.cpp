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
    vector<int> largestValues(TreeNode* root) {
        
         vector<int>ans;
         if(!root) return {};
         queue<TreeNode*>pq;
         pq.push(root);
         int maxval=INT_MIN;
         while(!pq.empty())
         {
            int n=pq.size();
            int maxval=INT_MIN;
            for(int i=0;i<n;i++)
            {
               TreeNode *temp=pq.front();
               pq.pop();
               //if(temp!=NULL)
               maxval=max(temp->val,maxval);
               if(temp->left) pq.push(temp->left);
               if(temp->right) pq.push(temp->right);
            }
            ans.push_back(maxval);
         }
         return ans;
    }
};