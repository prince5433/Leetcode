class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int currmax=neededTime[0];
        int mini=0;
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                mini+=min(currmax,neededTime[i]);
                currmax=max(currmax,neededTime[i]);
            } else{
                currmax=neededTime[i];
            }
        }
        return mini;
    }
};