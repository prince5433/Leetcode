class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26,0),upper(26,0);
        for(char ch:word){
            if(islower(ch)){
                lower[ch-'a']=1;
            } else {
                upper[ch-'A']=1;
            }
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(lower[i]==1 && upper[i]==1) cnt++;
        }
        return cnt;
    }
};