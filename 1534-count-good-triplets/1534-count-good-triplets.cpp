class Solution {
public:
    int countGoodTriplets(vector<int>& nums, int a, int b, int c) {
         int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if((abs(nums[i]-nums[j])<=a) &&(abs(nums[j]-nums[k])<=b) &&(abs(nums[i]-nums[k])<=c)) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};
