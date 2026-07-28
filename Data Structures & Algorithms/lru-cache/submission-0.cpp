class Node {
public:
    int key;
    int value;
    Node * p;
    Node * n;

    Node(int k, int v) : key(k), value(v), p(nullptr), n(nullptr) {}
}; // doubly ll

class LRUCache {
private:
    int c;
    unordered_map<int, Node*> cache;
    Node * l;
    Node * r;

    void insert(Node* node) {
        Node* p = r->p;
        p->n = node;
        node->p = p;
        node->n = r;
        r->p = node;
    }

    void remove(Node* node) {
        Node* prev = node->p;
        Node* nxt = node->n;
        prev->n = nxt;
        nxt->p = prev;
    }
    
public:
    LRUCache(int capacity) : c(capacity), l(new Node(0,0)), r(new Node(0,0)) {
        cache.clear();
        l->n = r;
        r->p = l;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);
        if (cache.size() > c) {
            Node* lru = l->n;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
