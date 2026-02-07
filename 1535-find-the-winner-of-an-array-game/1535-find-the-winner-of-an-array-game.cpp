class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        // INTUITION:
        // Game ko simulate karte hain aur current winner ke
        // consecutive wins count karte hain.
        // Maximum element kabhi haar nahi sakta, isliye
        // agar start me hi aa jaye to wahi answer ho sakta hai.

        // Maximum element nikaala
        int mx = *max_element(arr.begin(), arr.end());

        // Agar maximum element starting positions me hai
        // to wahi winner hoga
        if (arr[0] == mx || arr[1] == mx) return mx;

        unordered_map<int, int> win;  // har element ke consecutive wins
        int curr = arr[0];            // current winner

        // Game simulation
        for (int i = 1; i < n; i++) {
            if (curr > arr[i]) {
                // Current winner jeet gaya, win count badhao
                win[curr]++;
            } else {
                // Naya element jeeta, wahi current winner
                curr = arr[i];
                win[curr]++;
            }

            // Jaise hi kisi element ke k consecutive wins ho jaye
            // wahi final winner hoga
            if (win[curr] == k)
                return curr;
        }

        // Safety case: loop ke baad jo current hai wahi winner
        return curr;
    }
};
