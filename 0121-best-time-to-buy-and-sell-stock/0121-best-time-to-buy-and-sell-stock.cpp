class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minprice = INT_MAX;   // Ab tak ka minimum stock price (buy karne ke liye)
        int maxprice = 0;         // Maximum profit jo ab tak mil sakta hai

        // Har din ke stock price ko iterate kar rahe hain
        for(int price : prices) {

            // Minimum price update karte hain
            minprice = min(minprice, price);

            // Current price par sell karne ka profit calculate
            // price - minprice = profit
            maxprice = max(maxprice, price - minprice);
        }

        // Maximum possible profit return
        return maxprice;
    }
};
