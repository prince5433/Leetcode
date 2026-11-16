
class Solution {
public:
    string digitSum(string s, int k) {

        // Jab tak string ki length k se greater hai,
        // tab tak digit sum process repeat karenge.
        while(s.size() > k) {

            // Current round ke results store karne ke liye.
            string temp = "";

            // Har round mein string ki current length update hogi.
            int n = s.size();

            // String ko k-k characters ke groups mein divide karo.
            for(int i = 0; i < n; i += k) {

                int sum = 0;

                // Current group ke digits ka sum calculate karo.
                // i+k se aage aur n se bahar nahi jaana.
                for(int j = i; j < i+k && j < n; j++) {

                    sum += s[j] - '0';
                }

                // Current group ka sum temp mein append karo.
                temp += to_string(sum);
            }

            // Saare groups process hone ke baad
            // new string ko next round ka input banao.
            s = temp;
        }

        return s;
    }
};

/*
TIME COMPLEXITY:
Each round processes all characters of the current string.
For k >= 2 and bounded digit sums, the string shrinks
geometrically, giving O(n) total processing.

SPACE COMPLEXITY:
Temporary string = O(n).
Auxiliary SC = O(n).
*/
