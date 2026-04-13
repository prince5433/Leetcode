class Solution {
public:
    int getFreq(string s){
        int count[26] = {0};
        for(char c : s){
            count[c - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(count[i] > 0){
                return count[i];
            }
        }
        return 0;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            int fq = getFreq(queries[i]);
            int cnt = 0;

            for(auto &w : words){
                int fw = getFreq(w);
                if(fq < fw){
                    cnt++;
                }
            }

            ans[i] = cnt;
        }

        return ans;
    }
};