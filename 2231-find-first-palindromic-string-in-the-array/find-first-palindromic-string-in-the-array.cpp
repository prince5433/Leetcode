class Solution {
public:
bool isPali(string s){
    string copy=s;
    reverse(s.begin(),s.end());
    return  copy==s;
}
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            if(isPali(words[i])){
                return words[i];
                break;
            }
        }
        return "";
    }
};