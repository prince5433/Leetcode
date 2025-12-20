class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            ans.push_back(to_string(nums[i]));
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int a=ans[i][0]-'0';
                int b=ans[j].back()-'0';
                if(__gcd(a,b)==1) cnt++;
            }
        }
        return cnt;

    }
};