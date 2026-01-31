class Solution {
public:

    // start → current number jisse choices shuru hongi
    // n     → maximum number (1 to n)
    // k     → combination ka required size
    // current → abhi tak bani hui combination
    // result  → saari valid combinations store karne ke liye
    void f(int start, int n, int k,
           vector<int> &current,
           vector<vector<int>> &result) {

        // Base case:
        // agar current combination ka size k ho gaya
        // matlab ek valid combination mil chuki hai
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Agar start n se bada ho gaya
        // matlab ab koi number bacha hi nahi pick karne ke liye
        if (start > n) return;

        // ---------------- PICK CASE ----------------

        // current number ko combination me include karo
        current.push_back(start);          // do

        // next number se aage explore karo
        f(start + 1, n, k, current, result); // explore

        // backtracking: last added number hatao
        current.pop_back();                // undo

        // -------------- NOT PICK CASE --------------

        // current number ko skip karke aage badho
        f(start + 1, n, k, current, result);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> current;               // ek combination banane ke liye
        vector<vector<int>> result;        // final answer

        // recursion 1 se start hoti hai
        f(1, n, k, current, result);

        return result;
    }
};
