class Solution {
public:
int n;
vector<int> dp;
int solve(vector<int>& arr ,int i,int d){
    if(dp[i]!=-1) return dp[i];
    int result=1;
    //left (i-1,i-2...i-d)
    for(int j=i-1;j>=max(0,i-d);j--){
        if(arr[j]>=arr[i]) break;
        result=max(result,1+solve(arr,j,d));
    }
     for(int j=i+1;j<=min(n-1,i+d);j++){
        if(arr[j]>=arr[i]) break;
        result=max(result,1+solve(arr,j,d));
    }
    return dp[i]=result;
}
    int maxJumps(vector<int>& arr, int d) {
      n=arr.size();
      dp.clear();
      dp.resize(n+1,-1);
      int result=1;
      for(int i=0;i<n;i++){
        result=max(result,solve(arr,i,d));
      }  
      return result;
    }
};