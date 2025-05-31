class Solution {
public:
   //2 parameetrs change ho rhe haui and j to we use 2d dp
    // vector<vector<int>> dp;
    // int f(string& s1,string& s2,int i,int j){
    //     //i for s1 and j for s2
    //     //base cases
    //     if(i>=s1.size()) return 0;
    //     if(j>=s2.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(s1[i]==s2[j]){
    //         return dp[i][j]= 1+f(s1,s2,i+1,j+1);
    //     } else{
    //         return dp[i][j]=max(f(s1,s2,i+1,j),f(s1,s2,i,j+1));
    //     }
    // }
    vector<vector<int>> dp;
    int longestCommonSubsequence(string s1, string s2) {
        dp.clear();
        dp.resize(1005,vector<int>(1005,0));//for top down -1 se hi initlaize krenge

        //bottom up approach hai
        // 0 is liye kyoki hamar base case hi hai i>size to return 0;
        //hame kisis bhi ith jth state ke liyte aage ki sattes ki answer chahiye
        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){  
                 if(s1[i]==s2[j]){
                  dp[i][j]= 1+dp[i+1][j+1];
                }      
                 else{
                 dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                     }
                }
            }
            return dp[0][0];
        }
};