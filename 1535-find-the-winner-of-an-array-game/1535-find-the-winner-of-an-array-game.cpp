class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        // Maximum element kabhi haar nahi sakta
        int mx = *max_element(arr.begin(), arr.end());
        if (arr[0] == mx || arr[1] == mx) return mx;

        unordered_map<int, int> win;  // element -> consecutive wins
        int curr = arr[0];

        for (int i = 1; i < n; i++) {
            if (curr > arr[i]) {
                win[curr]++;          // curr wins again
            } else {
                curr = arr[i];        // new winner
                win[curr] = 1;
            }

            // Jaise hi k wins mile, wahi winner
            if (win[curr] == k)
                return curr;
        }

        // Safety (though max element hi jeetega)
        return curr;
    }
};
