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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode *>pq;
        pq.push(root);
        vector<int>ans;
        while(!pq.empty())
        {
            int n=pq.size();
            int sum=0;
            for(int i=0;i<n;i++)
            {
                 TreeNode *temp=pq.front();
                 pq.pop();
                 sum+=temp->val;
                 if(temp->left) pq.push(temp->left);
                  if(temp->right) pq.push(temp->right);
            }
            ans.push_back(sum);
        }
            int maxVal = INT_MIN;
    int minIndex = -1;

    // Find the maximum value
    for (int num : ans) {
        if (num > maxVal) {
            maxVal = num;
        }
    }

    // Find the first occurrence (minimum index) of maxVal
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == maxVal) {
           return i+1;
        }
    }

    return 0;

    }
};