class TrieNode {
public:
    vector<TrieNode*> child;
    bool eOw; 
    TrieNode() : eOw(false), child(26, nullptr) { }
};

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }
            cur = cur->children[i];
        }
        return cur->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }
            cur = cur->children[i];
        }
        return true;
    }
};