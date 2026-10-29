class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {

        // STEP 1: Original array ka total sum calculate karo.
        // Baad mein har element ko rearrange karke jo extra value
        // milegi, use isi sum mein add karenge.
        long long sum = 0;
        for (int x : nums) {
            sum += x;
        }

        // diff[i] store karega:
        // Digits ko descending order mein arrange karne ke baad
        // bani number - original number.
        // Ye batayega ki us element se kitna extra sum mil sakta hai.
        vector<int> diff;

        for (int x : nums) {

            // Integer ko string mein convert karo,
            // taaki uske digits ko independently sort kar sakein.
            string str = to_string(x);

            // Digits ko descending order mein sort karo.
            // Example: "273" -> "732"
            // Sabse bada digit pehle rakhne se maximum number banega.
            sort(str.rbegin(), str.rend());

            // Sorted digits wali string ko wapas integer mein convert karo.
            int number = stoi(str);

            // Extra gain calculate karo aur store karo.
            // Example: x = 273, number = 732
            // diff = 732 - 273 = 459
            diff.push_back(number - x);
        }

        // Sabse bade gains ko pehle rakhne ke liye descending sort.
        // Isse hum maximum benefit dene wale elements pehle choose karenge.
        sort(diff.rbegin(), diff.rend());

        // Top k gains ko original sum mein add karo.
        // Har iteration mein ek element ka extra gain include hota hai.
        for (int i = 0; i < k; i++) {
            sum += diff[i];
        }

        // Original sum + top k extra gains = maximum sum.
        return sum;
    }
};

/*
TIME COMPLEXITY:
O(n * d log d + n log n + k)
n = nums ka size, d = maximum digits per number.
Digits sort karne aur diff array sort karne ka time include hai.

SPACE COMPLEXITY: O(n * d)
diff array aur temporary digit strings ke liye.
*/