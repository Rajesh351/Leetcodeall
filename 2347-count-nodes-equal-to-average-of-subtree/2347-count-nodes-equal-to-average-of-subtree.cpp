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
    pair<int, int> sumAndCount(TreeNode* root) {
        if (!root)
            return {0, 0}; // {sum, count}

        pair<int, int> left = sumAndCount(root->left);
        pair<int, int> right = sumAndCount(root->right);

        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;

        return {sum, count};
    }

    // Function to calculate the number of nodes equal to the average of their
    // subtree
    int averageOfSubtree(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            pair<int, int> subtree = sumAndCount(temp);
            int sum = subtree.first;
            int count = subtree.second;

            // Check if the node's value is equal to the average of its subtree
            if (temp->val == sum / count) {
                ans++;
            }

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        return ans;
    }
};