class Solution {
public:
    int maxCoins(vector<int>& piles) {
     sort(piles.begin(),piles.end());
     int n=piles.size();
     int l=n/3;
     int sum=0;
     for(int i=n-2;i>=l;i-=2){
        sum+=piles[i];
     }
     return sum;
    }
};