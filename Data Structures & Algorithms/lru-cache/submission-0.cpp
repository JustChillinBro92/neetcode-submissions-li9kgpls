class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};


class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left; 
    Node* right;

    // remove any node
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // insert before right(dummy) i.e., most recent
    void insert(Node* node) {
        Node* rprev = right->prev;
        rprev->next = node;
        node->prev = rprev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* remNode = cache[key];
            // remove and insert node to make it most recent accessed
            remove(remNode);
            insert(remNode);
            return remNode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
            remove(cache[key]);

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        // evict & delete least recent node from list & cache, 
        // if cache exceeds capacity
        if(cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};