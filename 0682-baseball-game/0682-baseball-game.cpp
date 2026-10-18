class Solution {
public:
    int calPoints(vector<string>& arr) {
        int n = arr.size();

        // Stack mein sirf valid scores store honge.
        // C, D aur + jaise operations previous scores par depend karte hain.
        stack<int> st;

        // First operation numeric score hai, isliye use integer mein convert karke push karo.
        st.push(stoi(arr[0]));

        for(int i = 1; i < n; i++) {

            // "C" ka matlab previous round ka score cancel karna hai.
            // Isliye latest score ko stack se remove karenge.
            if(arr[i] == "C")
                st.pop();

            // "D" ka matlab previous score ka double current round mein add karna.
            // Top score ko remove nahi karna, bas uska double push karna hai.
            else if(arr[i] == "D")
                st.push(2 * st.top());

            // "+" ka matlab previous 2 valid scores ka sum add karna hai.
            else if(arr[i] == "+") {

                // Sum calculate karne ke liye stack mein kam se kam 2 scores hone chahiye.
                if(st.size() >= 2) {

                    // Latest score temporarily save karke pop kar rahe hain,
                    // taaki uske neeche wala previous score access kar sakein.
                    int top1 = st.top();
                    st.pop();

                    int top2 = st.top();

                    // top1 ko wapas push karna zaroori hai,
                    // kyunki "+" operation purane scores ko remove nahi karta.
                    st.push(top1);

                    // Dono previous scores ka sum naya score banega.
                    st.push(top1 + top2);
                }
            }

            // Agar operation C, D ya + nahi hai,
            // toh woh ek numeric score hai, jaise "5" ya "-3".
            else {
                st.push(stoi(arr[i]));
            }
        }

        // Saare valid rounds ke scores ka total calculate karenge.
        int ans = 0;

        while(st.size() > 0) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};