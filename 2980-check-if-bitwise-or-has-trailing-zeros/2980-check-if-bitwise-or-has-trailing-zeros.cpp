class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int n=nums.size();
        int ec=0;
        for(int num:nums){
            if(num%2==0) ec++;
        }
        return ec>=2;
    }
};