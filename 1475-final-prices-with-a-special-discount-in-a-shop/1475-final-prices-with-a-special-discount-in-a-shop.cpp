class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        // Direct next smaller or equal element store karenge.
        // 0 ka matlab koi discount nahi mila.
        vector<int> nse(n, 0);
        stack<int> st;

        // Last element ka NSE 0 hai,
        // lekin uski value stack mein push karenge.
        st.push(prices[n-1]);

        // Second-last element se traverse karenge.
        for(int i = n-2; i >= 0; i--) {

            // Current price se greater elements ko pop karo,
            // kyunki woh discount nahi de sakte.
            while(!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            // Stack top hi nearest smaller or equal price hai.
            if(!st.empty()) {
                nse[i] = st.top();
            }

            // Direct price push kar rahe hain, index nahi.
            st.push(prices[i]);
        }

        // Final price = Original price - Discount.
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            ans[i] = prices[i] - nse[i];
        }

        return ans;
    }
};