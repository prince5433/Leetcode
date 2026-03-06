class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string temp="";
        int n=words.size();
        for(string word:words){
            int sum=0;
            for(char ch:word){
                sum+=weights[ch-'a'];
            }
            int idx=sum%26;
            temp+=('z'-idx);
        }
        return temp;
    }
};