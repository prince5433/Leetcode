class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        unordered_set<char>seen;
        int count=1;//every string is a substring
        for(char c:s){
            if(seen.count(c)){
                count++;
                seen.clear();
            }
            seen.insert(c);
        }
        return count;
    }
};