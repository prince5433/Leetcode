class Solution {
public:
bool isVowel(char c){
    return (c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U');
}
    bool halvesAreAlike(string s) {
        int n=s.size();
        int cnt1=0;
        for(int i=0;i<n/2;i++){
            if(isVowel(s[i])) cnt1++;
        }
          int cnt2=0;
        for(int i=n/2;i<n;i++){
            if(isVowel(s[i])) cnt2++;
        }
        return cnt1==cnt2;
    }
};