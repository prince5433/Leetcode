class Solution {
public:
vector<vector<int>> dp;
int n;
int solve(int idx,vector<vector<int>>& items,int rem_budget,int mini,vector<int>& val){
    if(idx==n){
        return rem_budget/mini;
    }
    if(dp[idx][rem_budget]!=-1) return dp[idx][rem_budget];
    //skip
    int skip=solve(idx+1,items,rem_budget,mini,val);
    //nbuy
    int buy=0;
    if(rem_budget>=items[idx][1]){
        buy=val[idx]+solve(idx+1,items,rem_budget-items[idx][1],mini,val);
    }

    return dp[idx][rem_budget]=max(buy,skip);
}
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
         n=items.size();
        vector<int> val(n,1);//hr item ko khridne pr kitna item mil skta hai default 1 koki wo to milega hi
        int min_price=INT_MAX;
        //pre compute krlo ki hr item ko khridne pr kitna max mil skta hai ree item
        for(int i=0;i<n;i++){
            min_price=min(min_price,items[i][1]);
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]% items[i][0]==0){
                    val[i]++;
                }
            }
        }
        dp.assign(n,vector<int>(budget+1,-1));
        return solve(0,items,budget,min_price,val);
       
    }
};