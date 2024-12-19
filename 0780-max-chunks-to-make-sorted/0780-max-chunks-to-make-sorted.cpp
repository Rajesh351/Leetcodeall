class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
       int maxele=0;
       int count=0;
       for(int i=0;i<arr.size();i++)
       {
          maxele=max(arr[i],maxele);
          if(maxele==i) count++;
       }
       return count;
        
    }

    
};