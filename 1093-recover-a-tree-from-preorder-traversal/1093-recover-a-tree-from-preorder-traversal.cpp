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
   TreeNode* solve(string &s, int &i, int dep) {
        int n = s.size();
        if (i >= n) return NULL;

        int j = i;
        while (j < n && s[j] == '-') j++; // Count dashes

        int dash = j - i;
        if (dash != dep) return NULL; // If depth mismatch, return NULL
        i = j; // Move index to number part

        int num = 0;
        while (i < n && isdigit(s[i])) { // Extract number
            num = (num * 10) + (s[i] - '0');
            i++;
        }

        TreeNode *root = new TreeNode(num);
        root->left = solve(s, i, dep + 1);  // Construct left subtree
        root->right = solve(s, i, dep + 1); // Construct right subtree
        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        return solve(traversal, i, 0);
    }
};