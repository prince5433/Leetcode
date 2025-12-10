class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=numsDivide[0];
        int n=numsDivide.size();
        for(int i=1;i<n;i++){
            g=gcd(g,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(g%nums[i]==0) return i;
        }
        return -1;
    }
};