class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {

        // stack ka use adjacent equal elements ko merge karne ke liye
        // stack ke top par hamesha last processed element rahega
        stack<long long> st;

        int n = nums.size();

        // array ke har element par iterate
        for (int i = 0; i < n; i++) {

            // current number ko stack me push karo
            long long curr = nums[i];
            st.push(curr);

            /*
              Jab tak:
              - stack me kam se kam 2 elements hon
              - aur top aur uske niche wala element equal ho

              tab tak un dono ko merge karte raho
            */
            while (st.size() > 1) {

                // top element nikala
                long long top1 = st.top();
                st.pop();

                // second top element nikala
                long long top2 = st.top();
                st.pop();

                /*
                  Agar dono equal hain:
                  - unka sum bana ke wapas stack me push
                */
                if (top1 == top2) {
                    st.push(top1 + top2);
                } 
                /*
                  Agar equal nahi hain:
                  - wapas original order me stack me daal do
                  - aur loop break karo
                */
                else {
                    st.push(top2);
                    st.push(top1);
                    break;
                }
            }
        }

        // stack se answer vector banana
        // stack me elements reverse order me honge
        vector<long long> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // correct order ke liye reverse
        reverse(ans.begin(), ans.end());

        // final merged array return
        return ans;
    }
};
