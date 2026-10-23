
class Solution {
public:
    vector<vector<int>> result;

    void f(vector<int>& cand, int tgt, int idx, vector<int>& subset) {

        // INTUITION: Target 0 ho gaya matlab selected numbers ka sum
        // target ke equal hai, so ek valid combination mil gaya.
        if (tgt == 0) {
            result.push_back(subset);
            return;
        }

        // Saare candidates khatam, ab target banana possible nahi.
        if (idx == cand.size()) return;

        // PICK: Current candidate target se chhota ya equal hai,
        // toh use choose karke remaining target reduce kar sakte hain.
        if (cand[idx] <= tgt) {
            subset.push_back(cand[idx]);

            // idx+1: Har array element ko sirf ek baar use karna hai.
            f(cand, tgt - cand[idx], idx + 1, subset);

            // UNDO: Current choice hatao, taaki doosri combinations try hon.
            subset.pop_back();
        }

        // INTUITION: Sorted array mein equal adjacent values duplicates hain.
        // Current value ko NOT PICK karte waqt same value ke repeated
        // indices skip karo, warna identical combinations dobara banenge.
        // 1,2,2,2,5 if i am skipping one 2 in not pick then i have to skip all the 2 otherwise it willl lead to duplicate calls
        int j = idx + 1;
        while (j < cand.size() && cand[j] == cand[j - 1]) {
            j++;
        }

        // NOT PICK: Current value nahi lenge; next distinct value par jao.
        // Ye call cand[idx] > tgt hone par bhi valid hai.
        f(cand, tgt, j, subset);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sorting adjacent duplicates ko identify aur skip karna easy banati hai.
        sort(candidates.begin(), candidates.end());

        vector<int> subset;
        result.clear();

        f(candidates, target, 0, subset);
        return result;
    }
};

/*
TC: Worst-case approximately O(2^N * N), including copying valid subsets.
    N = candidates.size(); duplicate skipping may reduce the search.

SC: O(N) auxiliary space for recursion + current subset.
    Output storage is additional and depends on the number and size of answers.
*/
