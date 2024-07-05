
// https://leetcode.com/problems/lru-cache/description/


class Node{
    public:
    int key, value;
    Node*next, *prev;
    Node(int k, int v){
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};


class LRUCache {
public:
    int cap;
    Node*head = new Node(-1, -1);
    Node*tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node*node){
        Node*delNext = node->next;
        Node*delPrev = node->prev;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    void addNode(Node*node){
        Node*temp = head->next;
        head->next = node;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node*temp = mp[key];
            int ans = temp->value;
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node*temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }

        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;   

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */