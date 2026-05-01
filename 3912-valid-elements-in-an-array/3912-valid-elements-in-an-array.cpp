class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();

        // lmax[i] = i ke left side ka maximum element
        // rmax[i] = i ke right side ka maximum element
        vector<int> lmax(n);
        vector<int> rmax(n);

        // Prefix style:
        // current index se pehle tak ka sabse bada number store karenge
        for(int i = 1; i < n; i++) {
            lmax[i] = max(nums[i-1], lmax[i-1]);
        }

        // Suffix style:
        // current index ke baad tak ka sabse bada number store karenge
        for(int i = n-2; i >= 0; i--) {
            rmax[i] = max(nums[i+1], rmax[i+1]);
        }

        vector<int> ans;

        for(int i = 0; i < n; i++) {

            // first and last element hamesha valid hain
            // ya agar current element left ke sabse bade se bada hai
            // ya right ke sabse bade se bada hai
            if(i == 0 || i == n-1 || nums[i] > lmax[i] || nums[i] > rmax[i]) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};