class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> cnt(n+1,0);
        long long minPrice=1e18;
        for(auto& it:items){
            cnt[it[0]]++;
            minPrice=min(minPrice,(long long)it[1]);
        }
        vector<int> multiples(n+1,0);
        for(int f=1;f<=n;f++){
            if(cnt[f]==0)continue;
            for(int m=f;m<=n;m+=f){
                multiples[f]+=cnt[m];
            }
        }
        vector<pair<long long,int>> deals;
        for(auto&it:items){
            int f=it[0];
            long long p=it[1];
            int gain=multiples[f]-1;
            if(gain>0){
                deals.push_back({p,gain});
            }
        }
        sort(deals.begin(),deals.end());
        long long ans=0;
        long long remBudget=budget;
        for(auto&[price,gain]:deals){
            if(price>=2*minPrice) break;
            long long canbuy=min((long long)gain,remBudget/price);
            ans+=canbuy*2;
            remBudget-=canbuy*price;
        }
        ans+=remBudget/minPrice;
        return ans;
    }
};