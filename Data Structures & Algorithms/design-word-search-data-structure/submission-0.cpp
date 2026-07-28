class TrieNode {
public:
    vector<TrieNode*> child;
    bool eOw; 
    TrieNode() : eOw(false), child(26, nullptr) { }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() : root(new TrieNode()) {}
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            int i = c - 'a';
            if(curr->child[i] == nullptr){
                curr->child[i] = new TrieNode();
            } curr = curr->child[i];
        }
        curr->eOw = true;
    }
    
    bool search(string word) {
        return dfs(root, 0, word);
    }

    bool dfs(TrieNode* r, int d, string word){
        TrieNode* curr = r;
        for(int i{d}; i<word.size(); i++){
            char c = word[i];
            if(c=='.'){
                for(auto node : curr->child){
                    if(node && dfs(node, i+1, word)) return true;
                }
                return false;
            }
            else{
                int i = c - 'a';
                if(curr->child[i] == nullptr) return false;
                curr = curr->child[i];
            }
        }
        return curr->eOw;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */