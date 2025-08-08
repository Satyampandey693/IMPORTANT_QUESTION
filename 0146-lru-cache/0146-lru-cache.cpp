class LRUCache {
public:
struct Node{
    Node* prev;
    Node* next;
    int key;
    int val;
    Node(int key,int val):key(key),val(val),prev(NULL),next(NULL){
    }
};
Node* end;
Node* st;
map<int,Node*> mp;
int sz;

    LRUCache(int capacity) {
         sz=capacity;
         end=new Node(0,0);
          st=new Node(0,0);
          st->next=end;
          end->prev=st;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            int val=mp[key]->val;
            remove(mp[key]);
            insert(key,val);
            Node* node=mp[key];
           int va= node->val;
            // delete node;
            return va;

        }
        return -1;
    }
    private:
    void  insert(int key,int va){
        Node* node=new Node(key,va);
        node->prev=end->prev;
        end->prev->next=node;
        end->prev=node;
        node->next=end;
        mp[key]=node;
        //  mp.erase(key);
        // return node;
    }
    void remove(Node* node){
      node->next->prev=node->prev;
      node->prev->next=node->next;
      node->prev=NULL;
      node->next=NULL;
      mp.erase(node->key);
      delete node;
    }
    public:
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
           remove(mp[key]);
        }
       

        //  Node* newNode = new Node(key, value);
        // mp[key] = newNode;
        insert(key,value);

        if (mp.size() > sz) {
            Node* lru = st->next;
            remove(lru);
        }
        // mp[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */