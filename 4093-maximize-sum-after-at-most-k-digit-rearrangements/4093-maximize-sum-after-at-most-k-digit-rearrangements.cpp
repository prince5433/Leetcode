class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum=0;
        for(int x:nums) sum+=x;
        vector<int> diff;
        for(int x:nums){
            string str=to_string(x);
            sort(str.rbegin(),str.rend());
            int number=stoi(str);
            diff.push_back(number-x);
        }
        sort(diff.rbegin(),diff.rend());
        for(int i=0;i<k;i++){
            sum+=diff[i];
        }
        return sum;
    }
};