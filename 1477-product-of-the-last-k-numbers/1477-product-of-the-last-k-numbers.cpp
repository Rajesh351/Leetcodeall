class ProductOfNumbers {
public:
   vector<int>v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {

       int idx=v.size()-k;
       long long ans=1;
       for(int i=idx;i<v.size();i++)
       {
          if(v[i]==0) return 0;
          ans=ans*v[i];
       } 
       return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */