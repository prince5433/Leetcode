class Solution {
public:
#define ll long long
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<ll> ans(n,0);
        map<int,ll> idxsum;
        map<int,ll>idxcnt;
        
        for(int i=0;i<n;i++){
            ll freq=idxcnt[nums[i]];
            ll sum=idxsum[nums[i]];
            ans[i]+=freq*i-sum;
            idxcnt[nums[i]]+=1;
            idxsum[nums[i]]+=i;
        }
        idxsum.clear();
        idxcnt.clear();
         for(int i=n-1;i>=0;i--){
            ll freq=idxcnt[nums[i]];
            ll sum=idxsum[nums[i]];
            ans[i]+=sum-freq*i;
            idxcnt[nums[i]]+=1;
            idxsum[nums[i]]+=i;
        }
        return ans;
    }
};