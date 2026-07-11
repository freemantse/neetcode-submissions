class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val) : key{key}, val{val}, prev{nullptr}, next{nullptr} {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int,Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        insert(newNode);
        cache[key] = newNode;

        if (cache.size() > capacity) {
            Node* del = head->next;
            remove(del);
            cache.erase(del->key);
            delete del;
        }

        
        
    }
};
