class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int key1, int val1) {
            key = key1;
            val = val1;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> mpp;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Insert node just after head
    void insert_front(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Remove node from its current position
    void deletion(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key];

        deletion(node);
        insert_front(node);

        return node->val;
    }

    void put(int key, int value) {
        if (limit == 0) return;

        // Key already exists
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];

            node->val = value;

            deletion(node);
            insert_front(node);
        }
        else {
            // Capacity is full
            if (mpp.size() == limit) {
                Node* node = tail->prev;

                mpp.erase(node->key);
                deletion(node);
                delete node;
            }

            // Insert new node
            Node* node = new Node(key, value);

            mpp[key] = node;
            insert_front(node);
        }
    }
};