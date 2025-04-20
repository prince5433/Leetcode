class Solution {
public:
    int minPartitions(string n) {
        char maxd='0';
        for(auto &ch:n){
            if(ch>maxd){
                maxd=ch;
            }
        }
        return maxd-'0';
    }
};