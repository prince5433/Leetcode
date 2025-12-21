class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long>csum(26,0);
        int n=s.size();
        long long tsum=0;
        for(int i=0;i<n;i++){
            tsum+=cost[i];
            csum[s[i]-'a']+=cost[i];
        }
        long long maxv=0;
        for(int i=0;i<26;i++){
            maxv=max(maxv,csum[i]);
        }
        return tsum-maxv;
    }
};