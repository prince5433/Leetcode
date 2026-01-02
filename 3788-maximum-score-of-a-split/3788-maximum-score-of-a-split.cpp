class Solution {
public:
    #define ll long long   // long long ko short me ll likhne ke liye

    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        vector<ll> psum(n);   // psum[i] = nums[0] se nums[i] tak ka sum
        vector<ll> smin(n);   // smin[i] = nums[i] se nums[n-1] tak ka minimum

        // prefix sum build kar rahe hain
        psum[0] = nums[0];
        for(int i = 1; i < n; i++){
            psum[i] = psum[i-1] + nums[i];
        }

        // suffix minimum build kar rahe hain
        smin[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            smin[i] = min((ll)nums[i], smin[i+1]);
        }

        ll maxi = LLONG_MIN;  // maximum score store karega

        // valid split index: 0 se n-2 tak
        for(int i = 0; i < n-1; i++){
            // score = prefixSum(i) - suffixMin(i)
            // suffixMin(i) = smin[i+1]
            maxi = max(maxi, psum[i] - smin[i+1]);
        }

        return maxi;  // maximum score return
    }
};
