class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> miss;          // missing positive numbers store karne ke liye
        int curr = 1;              // current positive number (1 se start)
        int i = 0;                 // arr ka pointer

        // jab tak k missing numbers na mil jaye
        while (miss.size() < k) {

            // agar curr array me present hai
            if (i < arr.size() && arr[i] == curr) {
                i++;               // array pointer aage badhao
            } 
            // warna curr missing hai
            else {
                miss.push_back(curr); // missing number store karo
            }

            curr++;                // next positive number
        }

        return miss[k - 1];        // k-th missing positive number
    }
};
