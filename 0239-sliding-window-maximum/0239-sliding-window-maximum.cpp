class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();

        // NGI[i] = index of next greater element on the right.
        // Agar koi greater element nahi mila, toh n store karenge.
        int ngi[n];

        stack<int> st;

        // Last element ke right mein koi element nahi hai,
        // isliye sentinel index n store kar rahe hain.
        ngi[n-1] = n;
        st.push(n-1);

        // Right se left traverse karke next greater index find karo.
        for(int i = n-2; i >= 0; i--) {

            // Current element se chhote ya equal elements ko pop karo,
            // kyunki woh current element ke next greater nahi ho sakte.
            while(st.size() > 0 && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // Stack empty hai toh koi greater element nahi mila.
            if(st.size() == 0)
                ngi[i] = n;
            else
                ngi[i] = st.top();

            // Current index ko future elements ke liye store karo.
            st.push(i);
        }

        vector<int> ans;

        // j current window ke maximum candidate ko track karega.
        int j = 0;

        // Har possible sliding window ke liye maximum find karo.
        for(int i = 0; i < n-k+1; i++) {

            // j ko current window ke start se pehle nahi rehne dena.
            if(j < i) j = i;

            int mx = arr[j];

            // Current window ke end tak maximum candidate find karo.
            while(j < i+k) {

                // Current candidate ko maximum maan rahe hain.
                mx = arr[j];

                // Agar next greater element current window ke bahar hai,
                // toh current element hi window ka maximum hai.
                if(ngi[j] >= i+k) break;

                // Next greater element par jump karo.
                // Beech ke elements current candidate se chhote hain.
                j = ngi[j];
            }

            // Current window ka maximum answer mein add karo.
            ans.push_back(mx);
        }

        return ans;
    }
};