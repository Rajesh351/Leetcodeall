class Solution {
    public:
     int punishmentNumber(int n) {
        int sum =0;
        for(int i=1;i<=n;i++){
            int sqr = i*i;
            if(isPartition(sqr,i)) sum+=sqr;
        }return sum;
    }
    bool isPartition(int num,int tar){
        if(tar<0||num<tar) return false;
        if(num==tar) return true;
        return isPartition(num/10,tar-num%10) || isPartition(num/100,tar-num%100) ||isPartition(num/1000,tar-num%1000);
    }
};