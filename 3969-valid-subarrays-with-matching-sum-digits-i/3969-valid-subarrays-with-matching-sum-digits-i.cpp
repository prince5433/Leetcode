class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        int valid=0;
        for(int i=0;i<n;i++){
            long long csum=0;
            for(int j=i;j<n;j++){
                csum+=nums[j];

                if(csum%10==x){
                    long long temp=csum;
                    while(temp>=10){
                        temp/=10;
                    }
                    if(temp==x){
                        valid++;
                    }
                }
            }
        }
        return valid;
    }
};