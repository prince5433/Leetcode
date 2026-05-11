class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num:nums){
           string st = to_string(num);
           for(int i=0;i<st.length();i++){
            ans.push_back(st[i] - '0');
           }
        }
        return ans;
    }
};