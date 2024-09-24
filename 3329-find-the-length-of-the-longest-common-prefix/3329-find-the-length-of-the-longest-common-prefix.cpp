class TrieNode {
public:
    TrieNode* children[10]; 
    bool fromFirst = false, fromSecond = false;
    
    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
    
    void insert(int num, bool fromFirst) {
        string key = to_string(num);
        TrieNode* curr = this;
        for (char digChr : key) {
            int indx = digChr - '0';
            if (curr->children[indx] == nullptr) {
                curr->children[indx] = new TrieNode();
            }
            curr->children[indx]->fromFirst |= fromFirst;
            curr->children[indx]->fromSecond |= !fromFirst;
            curr = curr->children[indx];
        }
    }
};

class Solution {
private:
    int maxLen = 0;

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();
        for (int num : arr1) {
            root->insert(num, true);
        }
        for (int num : arr2) {
            root->insert(num, false);
        }
        findLongestPref(root, 0);
        return maxLen;
    }

    void findLongestPref(TrieNode* root, int depth) {
        maxLen = max(maxLen, depth);
        for (int i = 0; i < 10; ++i) {
            TrieNode* child = root->children[i];
            if (child != nullptr && child->fromFirst && child->fromSecond) {
                findLongestPref(child, depth + 1);
            }
        }
    }
};