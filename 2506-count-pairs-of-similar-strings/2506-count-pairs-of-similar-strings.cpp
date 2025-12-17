class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt=0;
        int n=words.size();
        for(int i=0;i<n-1;i++){
            set<char> s1(words[i].begin(),words[i].end());
         
            for(int j=i+1;j<n;j++){
              set <char>s2(words[j].begin(),words[j].end());
              if(s1==s2) cnt++;
            }
        }
        return cnt;
    }
};