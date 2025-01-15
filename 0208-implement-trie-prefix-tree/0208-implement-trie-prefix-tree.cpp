class Trie {
public:
    struct trieNode {
        bool endOfword;
        trieNode* children[26];
    };
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endOfword = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    trieNode* root ;
    Trie() {
         root = getNode(); 
    }

    void insert(string word) {
          trieNode* crawler = root;
    for (char ch : word) {
        if (crawler->children[ch - 'a'] == NULL) {
            crawler->children[ch - 'a'] = getNode();
        }
        crawler = crawler->children[ch - 'a'];
    }
    crawler->endOfword = true;
    }

    bool search(string word) {
        trieNode* crawler = root;
        for(auto it:word)
        {
            int idx=it-'a';
            if(crawler->children[idx]==NULL) return false;
            crawler=crawler->children[idx];
        }
        if( crawler->endOfword==true) return true;
         return false;
    }

    bool startsWith(string prefix) {
         trieNode* crawler = root;
        for(auto it:prefix)
        {
            int idx=it-'a';
            if(crawler->children[idx]==NULL) return false;
            crawler=crawler->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */