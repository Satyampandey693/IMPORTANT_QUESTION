class Trie {
public:
struct Node{
 vector<Node*> v;
 bool fl;
 Node(){
    v.assign(26,NULL);
    fl=false;
 }
};
Node* root;
    Trie() {
      root=new Node();  
    }
    
    void insert(string word) {
        Node* p=root;
        for(int i=0;i<word.size();i++){
               if(p->v[word[i]-'a']!=NULL){
                      p=p->v[word[i]-'a'];
               }
               else{
                Node* n=new Node();
                p->v[word[i]-'a']=n;
                p=n;
               }
        }
        p->fl=true;
    }
    
    bool search(string word) {
        Node* p=root;
        for(int i=0;i<word.size();i++){
               if(p->v[word[i]-'a']!=NULL){
                      p=p->v[word[i]-'a'];
               }
               else{
               return false;
               }
        } 
        return p->fl;
    }
    
    bool startsWith(string word) {
        Node* p=root;
         for(int i=0;i<word.size();i++){
               if(p->v[word[i]-'a']!=NULL){
                      p=p->v[word[i]-'a'];
               }
               else{
               return false;
               }
        } 
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */