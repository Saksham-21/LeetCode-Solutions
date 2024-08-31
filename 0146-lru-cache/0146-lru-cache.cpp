struct Node{
    int key;
    int val;
    Node* pre;
    Node* next;
    Node(int key_, int val_) {
        key = key_;
        val = val_;
        pre = NULL;
        next = NULL;
    }
};


class LRUCache {
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->pre = head;
    }
    void addNode(int key, int val) {
        Node* cur = new Node(key, val);
        Node* tmp = head->next;
        cur->next = tmp;
        cur->pre = head;
        head->next = cur;
        tmp->pre = cur;
    }
    void deleteNode(Node* cur) {
        Node* before = cur->pre;
        Node* after = cur->next;
        before->next = after;
        after->pre = before;
        delete cur;
    }
    int get(int key) {
        int val;
        if(mp.find(key)!=mp.end()){
            Node* curr=mp[key];
            val=curr->val;
            mp.erase(key);
            deleteNode(curr);
            addNode(key,val);
            mp[key]=head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // Node* curr;
        if(mp.find(key)!=mp.end()){
            Node* curr=mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        if(mp.size()==cap){
            Node* lru=tail->pre;
            mp.erase(lru->key);
            deleteNode(lru);
        }
        addNode(key,value);
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */