class Solution {
public:
    bool canAliceWin(int n) {
        int take=10;
        int step=0;
        while(n>=take){
            n-=take;
            take--;
            step++;
        }
        if(step&1)return true;
        else return false;
    }
};