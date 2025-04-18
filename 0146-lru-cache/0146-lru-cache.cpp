class LRUCache {
public:
    class Node{
        public: 
            int key, value;
            Node* next;
            Node* prev;

            Node(int k, int v){
                key = k;
                value = v;
                next = prev = NULL;
            }
        };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* newNode){
        Node* oldNode = head->next;
        head->next = newNode;
        newNode->prev = head;

        newNode->next = oldNode;
        oldNode->prev = newNode;
    }

    void delNode(Node* oldNode){
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->value;

        m.erase(key);
        delNode(ansNode);

        m[key] = ansNode;
        addNode(ansNode);
    
        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            m.erase(oldNode->key);
            delNode(oldNode);
        }
        if(m.size() == limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        m[key] = newNode;
        addNode(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */