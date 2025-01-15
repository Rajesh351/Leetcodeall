class Solution {
public:
    struct trieNode {
        bool endfowrod;
        trieNode* children[26];
    };
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endfowrod = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    void insert(string word, trieNode *root) {
        trieNode* crawler = root;
        for (char ch : word) {
            if (crawler->children[ch - 'a'] == NULL) {
                crawler->children[ch - 'a'] = getNode();
            }
            crawler = crawler->children[ch - 'a'];
        }
        crawler->endfowrod = true;
    }
    string findword(string str, trieNode *root) {
        trieNode* crawler = root;
        string ans = "";
        for (auto it : str) {
            ans += it;
            int idx = it - 'a';
            
            if (crawler->children[idx] == NULL)
                return str;
            crawler = crawler->children[idx];
             if (crawler->endfowrod == true) return ans;
        }
        if (crawler->endfowrod == true) return ans;
            return str;
    }
    string replaceWords(vector<string>& dict, string sentence) {

        trieNode* root = getNode();
        for (string str : dict) {
            insert(str, root);
        }
        stringstream ss(sentence);

        string word;
        string ans="";
        while (ss >> word) {
            string str = findword(word, root);
            ans += str;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};