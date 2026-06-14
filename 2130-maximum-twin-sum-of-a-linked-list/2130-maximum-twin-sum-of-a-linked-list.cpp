class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;

        while(head) {
            v.push_back(head->val);
            head = head->next;
        }

        int n = v.size();
        int ans = 0;

        for(int i = 0; i < n / 2; i++) {
            ans = max(ans, v[i] + v[n - 1 - i]);
        }

        return ans;
    }
};