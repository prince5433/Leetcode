class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int result = 0;
        
        for(int i = 0; i < n; i++){
            int val = 26 - (s[i] - 'a');  // 'a'->26, 'b'->25, etc
            result += (i + 1) * val;      // multiply by position in original string
        }
        
        return result;
    }
};
