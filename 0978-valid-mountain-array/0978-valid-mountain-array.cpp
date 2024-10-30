class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()< 3) return false;
        
        int i=0;
        bool a=true,b=true;
        while(i<arr.size()-1)
        {
            if(arr[i]<arr[i+1])
            {
                i++;
                a=false;
            }
            else if(arr[i]==arr[i+1]) return false;
            else break;
        }
          while(i<arr.size()-1)
        {
            if(arr[i]>arr[i+1])
              {
                i++;
                b=false;
            }
            else if(arr[i]==arr[i+1]) return false;
            else break;
        }
        if(i==arr.size()-1)
        {
            if(b==false && a==false) return true;
            else return false;
        }
        return false;

    }
};