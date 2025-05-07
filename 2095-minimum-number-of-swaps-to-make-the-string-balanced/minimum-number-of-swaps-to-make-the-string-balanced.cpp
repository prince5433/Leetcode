class Solution {
public:
    int minSwaps(string s) {
        int maxibalance=0,balance=0;
        for(char c:s){
            if(c=='[') balance++;
            else {
                balance--;
            }
            if(balance<0) maxibalance=max(maxibalance,-balance);
        }
        return (maxibalance+1)/2;
    }
};