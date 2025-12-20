class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>r0,r1,r2;
        for(int num:nums){
            if(num%3==0) r0.push_back(num);
            else if(num%3==1) r1.push_back(num);
            else r2.push_back(num);
        }

            sort(r0.rbegin(),r0.rend());
            sort(r1.rbegin(),r1.rend());
            sort(r2.rbegin(),r2.rend());

            int maxi=0;
            if(r0.size()>=3){
                maxi=max(maxi,r0[0]+r0[1]+r0[2]);
            }
            if(r1.size()>=3){
                maxi=max(maxi,r1[0]+r1[1]+r1[2]);
            }
             if(r2.size()>=3){
                maxi=max(maxi,r2[0]+r2[1]+r2[2]);
            }
            if(r0.size()>=1 && r1.size()>=1 && r2.size()>=1){
                maxi=max(maxi,r0[0]+r1[0]+r2[0]);
            }
        return maxi;
    }
};