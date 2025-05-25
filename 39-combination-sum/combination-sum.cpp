class Solution {
public:
void combination(vector<vector<int>>& ans,vector<int> v, vector<int>& candidates,  int target,int idx){
    if(target==0){
        ans.push_back(v);
        return;
    }
    if(target<0) return;
    for(int i=idx;i<candidates.size();i++){
        v.push_back(candidates[i]);
        combination(ans,v,candidates,target-candidates[i],i);
        v.pop_back();// taki if 2 agr gya in the array thenn next time only 3 jaye instead of {2,3}
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
         vector<int> v;
         combination(ans,v,candidates,target,0);
         return ans;
    }
};