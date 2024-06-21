class Solution {
public:
    int maxSatisfied(vector<int>& arr, vector<int>& v, int k) {


        int prvloss=0;
        for(int i=0;i<k;i++)
        {
            if(v[i]==0) prvloss+=arr[i];
        }
        int n=arr.size();
        int maxloss=prvloss;
        int maxindex=0;
        int i=1;
        int j=k;
        while(j<n)
        {
            int currloss=prvloss;
            if(v[j]==1) currloss+=arr[j];
            if(v[i-1]==1) currloss-=arr[i-1];
            if(maxloss<currloss)
            {
                maxloss=currloss;
                maxindex=i;
            }
            prvloss=currloss;
            i++;
            j++;
        }
        for(int i=maxindex;i<k+maxindex;i++)
        {
            v[i]=0;
        }
        int max1loss=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0) max1loss+=arr[i];
        }
        return max1loss;
       
    }
    
};