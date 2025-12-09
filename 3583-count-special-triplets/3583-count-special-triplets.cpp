class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        const long long MOD =1e9+7;
        unordered_map<long long,long long>left,right;
        long long ans=0;
        for(int x:nums) right[x]++;
        for(int x:nums){
            right[x]--;
            long long tgt=2LL*x;
            ans+=(left[tgt]*right[tgt])%MOD;
            left[x]++;
        }
        return ans%MOD;
    }
};