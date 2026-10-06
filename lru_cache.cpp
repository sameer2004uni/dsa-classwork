class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };

    unordered_map<int, Node*> mp;
    Node *head, *tail;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;

        p->next = n;
        n->prev = p;
    }

    void insert(Node* node) {
        Node* p = tail->prev;

        p->next = node;
        node->prev = p;

        node->next = tail;
        tail->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            remove(node);
            mp.erase(key);
        }

        Node* newNode = new Node(key, value);

        insert(newNode);
        mp[key] = newNode;

        if (mp.size() > capacity) {
            Node* lru = head->next;

            remove(lru);
            mp.erase(lru->key);
        }
    }
};
