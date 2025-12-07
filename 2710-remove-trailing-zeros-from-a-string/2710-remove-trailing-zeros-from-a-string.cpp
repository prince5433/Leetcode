class Solution {
public:
    string removeTrailingZeros(string num) {
        int n=num.size();
        int idx=-1;
        for(int i=n-1;i>=0;i--){
            if(num[i]!='0'){
                idx=i;
                break;
            }
        }
        string t=num.substr(0,idx+1);
        return t;
    }
};