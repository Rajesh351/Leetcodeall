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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> node;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto a = q.front();
            q.pop();
            TreeNode* ele = a.first;
            int ver = a.second.first;
            int lev = a.second.second;
            node[ver][lev].insert(ele->val);
            if (ele->left)
                q.push({ele->left, {ver - 1, lev + 1}});
            if (ele->right)
                q.push({ele->right, {ver + 1, lev + 1}});
        }
        vector<vector<int>> ans;
        for (auto p : node) {
            vector<int> v;
            for (auto q : p.second) {
                v.insert(v.end(), q.second.begin(),q.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};