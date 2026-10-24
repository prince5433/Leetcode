class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m) return false;

        vector<char> as1(26,0);
        vector<char> as2(26,0);

        for(char c:s1){
            as1[c-'a']++;
        }

         int i=0;
        int j=0;
        while(j<m){
            as2[s2[j]-'a']++;

            if(j-i+1>n){
                as2[s2[i]-'a']--;
                i++;
            }
            if(j-i+1==n && as1==as2){
                return true;
            }
            j++;
        }
        return false;
    }
};