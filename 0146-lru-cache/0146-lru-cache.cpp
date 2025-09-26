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
        return val;

       }
       return -1;
    }
    private:
    void insert(int k,int v){
        Node* n=new Node(k,v);
        mp[k]=n;
        end->prev->next=n;
        n->prev=end->prev;
        end->prev=n;
        n->next=end;

    }
    void remove(Node* nd){
        // cout<<nd->key<<" "<<nd->prev->key<<" "<<nd->next->key;
       nd->prev->next=nd->next;
       nd->next->prev=nd->prev;
       nd->prev=NULL;
       nd->next=NULL;
       mp.erase(nd->key);
       delete nd;
    }
   
    public:
    void put(int key, int value) {
       
        // mp[key]=node;
        if(mp.find(key)!=mp.end()){
            // sz--;
            remove(mp[key]);
        }
        if(sz<=mp.size()){
            remove(st->next);
        }
        insert(key,value);

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */