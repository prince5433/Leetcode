class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int cnt=0;
        while(i<j){
            if(nums[i]!=0) i++;
            else if(nums[j]==0) j--;
            else {
                swap(nums[i],nums[j]);
                cnt++;
                i++;
                j--;
            }
        }
        return cnt;
    }
};