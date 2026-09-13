class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq,last,first;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(first.find(nums[i])==first.end()){
                first[nums[i]]=i;
            }
            last[nums[i]]=i;
        }
        int cnt=0;
        for(auto it:freq){
            int x=it.first;
            if(last[x]-first[x]+1==freq[x]) cnt++;
        }
        return cnt;
    }
};