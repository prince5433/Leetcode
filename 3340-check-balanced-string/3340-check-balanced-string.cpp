class Solution {
public:
    bool isBalanced(string num) {
        int es=0,os=0;
        for(int i=0;i<num.size();i++){
            if(i%2==0) es+=num[i]-'0';
            else os+=num[i]-'0';
        }
        return es==os;

        }
};