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
   vector<TreeNode*> generateAllTrees(int n) {
    if (n % 2 == 0) {
        // If n is even, it's impossible to form a full binary tree
        return {};
    }
    if (n == 1) {
        // Base case: a single node tree
        return {new TreeNode(0)};
    }
    
    vector<TreeNode*> result;

    // Try splitting nodes between left and right subtrees
    for (int left_nodes = 1; left_nodes < n; left_nodes += 2) {
        int right_nodes = n - 1 - left_nodes; // Remaining nodes go to the right subtree

        // Generate all combinations of left and right subtrees
        vector<TreeNode*> left_trees = generateAllTrees(left_nodes);
        vector<TreeNode*> right_trees = generateAllTrees(right_nodes);

        // Combine each pair of left and right subtrees
        for (TreeNode* left : left_trees) {
            for (TreeNode* right : right_trees) {
                TreeNode* root = new TreeNode(0); // Create root node
                root->left = left;
                root->right = right;
                result.push_back(root); // Add the tree to the result
            }
        }
    }
    return result;
}
vector<TreeNode*> allPossibleFBT(int n) { 
    return generateAllTrees(n);
 }
};