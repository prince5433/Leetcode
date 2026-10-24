class Solution {
public:
void f(vector<int>& nums,int idx,vector<int>& subset,vector<vector<int>>& result){
    //base case
    if(idx==nums.size()){
        result.push_back(subset);
        return;
    }
    //pick 
    subset.push_back(nums[idx]);//do
    f(nums,idx+1,subset,result);//explore
    subset.pop_back();//undo

    //not pick me hi duplicate wali call probem dengi to skip duplicates
    // int j=idx+1;
    // while(j<nums.size() && nums[j]==nums[j-1]) continue;

    //not pick
    f(nums,idx+1,subset,result);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(),nums.end());//taki duplicates easiluy skip hoke handle hojaye
        f(nums,0,subset,result);
        return result;
    }
};