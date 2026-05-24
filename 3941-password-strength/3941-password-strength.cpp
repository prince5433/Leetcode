class Solution {
public:
    int passwordStrength(string password) {
        map<char,int> mp;
        int n=password.size();
        for( char ch='a';ch<='z';ch++){
            mp[ch]=1;
        }
           for( char ch='A';ch<='Z';ch++){
            mp[ch]=2;
        }
        for( char ch='0';ch<='9';ch++){
            mp[ch]=3;
        }
        mp['!']=5;
        mp['#']=5;
        mp['@']=5;
        mp['$']=5;
        set<char>st;
        for(char ch:password){
            st.insert(ch);
        }
        int sum=0;
        for(auto it:st){
            sum+=mp[it];
        }
        return sum;
    }
};