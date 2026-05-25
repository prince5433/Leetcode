class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n=nums.size();
        vector<int> ans;
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                mp[nums[i]].push_back(i);
            }
        }
        for(auto it :queries){
           if(it<=mp[x].size()){
            ans.push_back(mp[x][it-1]);
           } else{
            ans.push_back(-1);
           }
        }
        return ans;
    }
    
};