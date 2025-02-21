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
class FindElements {
public:
    unordered_map<int,int>mp;
    FindElements(TreeNode* root) {
        queue<TreeNode*>pq;
        root->val=0;
        pq.push(root);
        while(!pq.empty())
        {
           int n=pq.size();
           for(int i=0;i<n;i++)
           {
              TreeNode *ans=pq.front();
               mp[ans->val]++;
               int x=ans->val;
              pq.pop();
              if(ans->left)
              {
                 ans->left->val=2 * x + 1;
                 pq.push(ans->left);
              }
              if(ans->right)
              {
                ans->right->val=2 * x + 2;
                pq.push(ans->right);
              }
           }
        }
    }
    
    bool find(int target) {
       return mp.find(target)!=mp.end();
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */