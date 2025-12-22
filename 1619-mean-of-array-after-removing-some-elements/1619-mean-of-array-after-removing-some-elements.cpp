class Solution {
public:
    double trimMean(vector<int>& arr) {

        // Sort the array to remove smallest & largest elements easily
        sort(arr.begin(), arr.end());

        int n = arr.size();

        // Number of elements to remove from each side (5%)
        int five = n * 5 / 100;   // must be int, not double

        double ts = 0;            // total sum after trimming

        // Sum elements excluding lowest 5% and highest 5%
        for (int i = five; i < n - five; i++) {
            ts += arr[i];
        }

        // Remaining element count = n - 2 * five
        return ts / (n - 2 * five);
    }
};
