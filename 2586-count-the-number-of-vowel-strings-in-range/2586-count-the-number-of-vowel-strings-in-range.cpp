class Solution {
public:
bool isVowel(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt=0;
        for(int i=left;i<=right;i++){
            string temp=words[i];
            int n=temp.size();
             if(isVowel(temp[0]) && isVowel(temp[n-1])){
                cnt++;
            }
        }
        return cnt;
    }
};