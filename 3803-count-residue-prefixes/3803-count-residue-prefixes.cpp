class Solution {
public:
    int residuePrefixes(string s) {
        set<char>st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);

            if(st.size()>2) break;
            if(st.size()==(i+1)%3) ans++;
        }
        return ans;
    }
};