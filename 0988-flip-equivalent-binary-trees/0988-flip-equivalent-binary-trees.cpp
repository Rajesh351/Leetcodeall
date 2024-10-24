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
   bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;  // Both trees are empty
    if (root1 == NULL || root2 == NULL) return false; // One tree is empty, the other is not
    if (root1->val != root2->val) return false;       // Values of the roots do not match

    // Check if the children are flip equivalent
    // We can either compare the left with left and right with right,
    // or compare left with right and right with left (flipped case)
    bool noFlip = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    bool flip = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);

    return noFlip || flip; // Return true if either non-flip or flip equivalence is found
}

};