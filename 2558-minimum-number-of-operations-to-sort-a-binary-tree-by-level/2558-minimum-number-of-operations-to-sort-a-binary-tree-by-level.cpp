/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // Code here
       unordered_map<int , int> mp;
        vector<int> arr(nums.begin(), nums.end());
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]=i ;
        }
        int count=0 ;
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]]!=i){
                count++ ;
                swap(nums[i], nums[mp[nums[i]]]);
                i-- ; // i= -1
            }
            // i++ i.e. i=-1+1=0 ;
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        if (!root)
            return 0;
       int count=0;
        while (q.size()) {
            int swaps= 0;
            vector<int> v;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
          count+=minSwaps(v);
        }
        return count;
    }
};