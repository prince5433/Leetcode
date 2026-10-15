class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;

        // Linked list ki values directly vector mein store karo.
        ListNode* temp = head;
        while(temp) {
            res.push_back(temp->val);
            temp = temp->next;
        }

        int len = res.size();
        if(len == 0) return {};

        vector<int> ans(len, 0);
        stack<int> st;

        // Last element ke right mein koi element nahi hai.
        st.push(res[len-1]);

        // Right se left traverse karke next greater find karo.
        for(int i = len-2; i >= 0; i--) {

            // Chhote ya equal elements ko remove karo.
            while(!st.empty() && st.top() <= res[i]) {
                st.pop();
            }

            // Stack empty hai toh greater element nahi mila.
            if(st.empty()) ans[i] = 0;
            else ans[i] = st.top();

            // Current element ko future candidates mein add karo.
            st.push(res[i]);
        }

        return ans;
    }
};