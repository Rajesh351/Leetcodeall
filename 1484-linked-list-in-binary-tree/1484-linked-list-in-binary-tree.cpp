class Solution {
public:
    bool solve(ListNode* head, TreeNode* root) {
        if (head == NULL) 
            return true; // We have matched the entire list
        if (root == NULL) 
            return false; // Reached the end of the tree but the list is not fully matched

        // If values match, try to continue matching the next list node with the left and right subtrees
        if (head->val == root->val) {
            return solve(head->next, root->left) || solve(head->next, root->right);
        }

        // If values don't match, return false
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL) 
            return false;

        // Check if the current tree node matches the list from the head
        // Or recursively check the left and right subtrees
        return solve(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
