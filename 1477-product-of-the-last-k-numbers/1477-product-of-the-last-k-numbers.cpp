class ProductOfNumbers {
public:
vector<int> pr;
int lsZ=-1;
    ProductOfNumbers() {
        //h
    }
    
    void add(int num) {
         int  p;
        //  cout<<pr.size()<<" ";
        if(num==0) {lsZ=pr.size();
        pr.push_back(1);
        return ;}
        // if(pr.size()>0)
        // cout<<pr.back();
        if(pr.size()>0)
       p=pr.back()*num;
       else p=num;
    //    cout<<p<<endl;
       pr.push_back(p);

    }
    
    int getProduct(int k) {
        // cout<<pr[0];
        int p=pr[pr.size()-1];
        // cout<<pr.size()-k<<" "<<lsZ<<" "<<p<<" ";
        //  cout<<pr.size()<<" "<<pr.size()-k-1<<" "<<p<<" "<< pr[pr.size()-k-1]<<endl;
        if(((int)pr.size()-k)<=lsZ) {
        // cout<<"K";
        // cout<<endl;
        return 0;
        }
          

        //   cout<<p<<endl;
       
          if(k<pr.size())
         p=p/pr[pr.size()-k-1];
        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */