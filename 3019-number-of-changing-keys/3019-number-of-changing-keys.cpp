class Solution {
public:
    int countKeyChanges(string s) {
        // Convert full string to lowercase
        for(char &c : s) c = tolower(c);

        int cnt = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] != s[i + 1]) cnt++;
        }
        return cnt;
    }
};
