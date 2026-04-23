class Solution {
public:
#define ll long long
    vector<long long> getDistances(vector<int>& nums) {
         int n = nums.size();
        
        // Final answer array
        vector<ll> ans(n, 0);
        
        // idxsum[val] = sum of indices where 'val' has appeared so far
        // idxcnt[val] = count of occurrences of 'val' so far
        map<int, ll> idxsum;
        map<int, ll> idxcnt;
        
        // -------- LEFT TO RIGHT PASS --------
        for(int i = 0; i < n; i++) {
            
            // Number of same elements seen before
            ll freq = idxcnt[nums[i]];
            
            // Sum of indices of same elements seen before
            ll sum = idxsum[nums[i]];
            
            /*
            INTUITION:
            For all previous same elements at indices j:
            contribution = (i - j)
            
            Total = i*freq - sum(j)
            */
            ans[i] += freq * i - sum;
            
            // Update maps
            idxcnt[nums[i]] += 1;
            idxsum[nums[i]] += i;
        }
        
        // Clear maps for second pass
        idxsum.clear();
        idxcnt.clear();
        
        // -------- RIGHT TO LEFT PASS --------
        for(int i = n - 1; i >= 0; i--) {
            
            ll freq = idxcnt[nums[i]];
            ll sum = idxsum[nums[i]];
            
            /*
            INTUITION:
            For all future same elements at indices j:
            contribution = (j - i)
            
            Total = sum(j) - i*freq
            */
            ans[i] += sum - freq * i;
            
            // Update maps
            idxcnt[nums[i]] += 1;
            idxsum[nums[i]] += i;
        }
        
        return ans;
    }
};