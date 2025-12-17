class Solution {
public:
    bool digitCount(string num) {
        int n=num.size();
        vector<int> freq(10,0);
        for(char c:num){
            freq[c-'0']++;
        }
        for(int i=0;i<n;i++){
            if(freq[i]!=num[i]-'0') return false; 
        }
        return true;
    }
};