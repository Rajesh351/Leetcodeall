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


int nodeLevel[1000001];
int nodeHeight[100001];
int maxHeightAtLevel[100001];
int secondMaxHeightAtLevel[100001];

int solve(TreeNode *root, int level) {
    if (!root) return 0;
    
    nodeLevel[root->val] = level;
    nodeHeight[root->val] = max(solve(root->left, level + 1), solve(root->right, level + 1)) + 1;
    
    if (maxHeightAtLevel[level] < nodeHeight[root->val]) {
        secondMaxHeightAtLevel[level] = maxHeightAtLevel[level];
        maxHeightAtLevel[level] = nodeHeight[root->val];
    }
    else if (secondMaxHeightAtLevel[level] < nodeHeight[root->val]) {
        secondMaxHeightAtLevel[level] = nodeHeight[root->val];
    }
    
    return nodeHeight[root->val];
}

vector<int> treeQueries(TreeNode* root, vector<int>& arr) {
    solve(root,0);
    vector<int> result;
    for (int node : arr) {
        int levelOfNode = nodeLevel[node];
        int tempResult = levelOfNode + (maxHeightAtLevel[levelOfNode] == nodeHeight[node] ? secondMaxHeightAtLevel[levelOfNode] : maxHeightAtLevel[levelOfNode]) - 1;
        result.push_back(tempResult);
    }
    return result;
}

};