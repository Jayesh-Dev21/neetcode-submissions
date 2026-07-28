class TrieNode {
public:
    vector<TrieNode*> child;
    bool eOw; 
    TrieNode() : eOw(false), child(26, nullptr) { }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() { 
        this->root = new TrieNode(); 
    }
    
    void insert(string word) {
        if(word == "") return;
        TrieNode* curr = root;
        for(char s : word){
            int i = s - 'a';
            if(curr->child[i] == nullptr){
                curr->child[i] = new TrieNode();
            }
            curr = curr->child[i];
        }
        curr->eOw = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char s: word){
            int i = s - 'a';
            if(curr->child[i] == nullptr){
                return false;
            }
            curr = curr->child[i];
        }
        return curr->eOw;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char s: prefix){
            int i = s - 'a';
            if(curr->child[i] == nullptr){
                return false;
            }
            curr = curr->child[i];
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