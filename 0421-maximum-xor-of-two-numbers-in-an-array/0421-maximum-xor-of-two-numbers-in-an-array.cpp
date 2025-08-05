struct Node{
    Node* arr[2];

    bool containKey(int i){
        return arr[i]!=NULL;
    }

    Node* get(int i){
        Node* node=new Node();
        arr[i]=node;
        return node;
    }

    Node* next(int i){
        return arr[i];
    }
};
class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }

    void insert(int n){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(!node->containKey(bit)){
                node=node->get(bit);
            }
            else node=node->next(bit);

        }
    }


     int findXor(int n){
         Node* node=root;
         int xorr=0;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            int nb=!bit;
            if(node->containKey(nb)){
                xorr=xorr|(1<<i);
                node=node->next(nb);

            }
            else{ 
                node=node->next(bit);
                }

        }
        cout<<xorr<<" ";
        return xorr;
     }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie=new Trie();
        for(int i=0;i<nums.size();i++){
            trie->insert(nums[i]);
        }
          int ans=0;
        for(int i=0;i<nums.size();i++){
          int p= trie->findXor(nums[i]);
          ans=max(ans,p);
        }

return ans;

        

    }
};