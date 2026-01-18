class Solution {
public:
bool isVowel(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;
        int n=s.size();
        int maxc=0;
        int c=0;
        while(j<n){
            if(isVowel(s[j])){
                c++;
            }
            if(j-i+1==k){
                maxc=max(maxc,c);
                if(isVowel(s[i])){
                    c--;
                }
                i++;
            }
            j++;
            
        }
        return maxc;
    }
};