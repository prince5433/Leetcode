class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum=0;
        int sqsum=0;
        while(n>0){
            int d=n%10;
            sum+=d;
            sqsum+=d*d;
            n/=10;
        }
        if((sqsum-sum)>=50) return true;
        return false;
    }
};