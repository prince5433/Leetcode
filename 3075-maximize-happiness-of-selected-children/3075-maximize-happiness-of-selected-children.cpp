class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long total=0;
        for(int i=0;i<k;i++){
            total+=max(happiness[i]-i,0);
        }
        return total;
    }
};