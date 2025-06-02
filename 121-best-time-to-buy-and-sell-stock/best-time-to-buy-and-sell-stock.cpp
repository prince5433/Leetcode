class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX,maxprice=0;
        for(int price:prices){
            minprice=min(minprice,price);
            maxprice=max(maxprice,price-minprice);
        }
        return maxprice;
    }
};