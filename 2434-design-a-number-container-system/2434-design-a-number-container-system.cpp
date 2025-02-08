class NumberContainers {
public:
map<int,int> m;
map<int,set<int>> mp;
    NumberContainers() {
        
    }
    
    void change(int ind, int number) {
        if(m[ind]){
           mp[m[ind]].erase(ind);
           mp[number].insert(ind);
           m[ind]=number;
          
        }
        else{
          m[ind]=number;
           mp[number].insert(ind);
        }
       
    }
    
    int find(int number) {
        int p=-1;
        int c=0;
        for(auto i:mp[number]){
            p=i;
            if(c==0) break;
        }
        return p;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */