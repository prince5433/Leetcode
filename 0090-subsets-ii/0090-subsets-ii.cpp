
class Solution {
public:
    /*
    QUESTION: SUBSETS II

    Given an array nums that may contain duplicates, return all
    possible unique subsets (power set).

    Example:
    nums = [1, 2, 2]

    Output:
    [], [1], [2], [1,2], [2,2], [1,2,2]

    INTUITION:
    Har element ke liye PICK ya NOT PICK choose kar sakte hain.
    Lekin equal elements ki wajah se same subset multiple times
    generate ho sakta hai. Sorting + duplicate skipping se isse bachenge.
    */

    void f(vector<int>& nums, int idx, vector<int>& subset,
           vector<vector<int>>& result) {

        // BASE CASE: Saare elements ke decisions complete ho gaye.
        // Current subset ek complete possibility hai, ise save karo.
        if (idx == nums.size()) {
            result.push_back(subset);
            return;
        }

        // PICK: Current element ko include karo.
        // INTUITION: Is choice se woh saare subsets explore honge
        // jinmein nums[idx] present hai.
        subset.push_back(nums[idx]);
        f(nums, idx + 1, subset, result);

        // UNDO: PICK branch ke baad element hatao, taaki NOT PICK
        // branch current element ke bina explore kar sake.
        subset.pop_back();

        // NOT PICK: Current value ko skip karte waqt, uske baad aane
        // wale same values ko bhi skip karo. Array sorted hai, isliye
        // duplicates adjacent hain. Warna identical subsets repeat honge.
        int j = idx + 1;
        while (j < nums.size() && nums[j] == nums[j - 1]) {
            j++;
        }

        // Ab next distinct value se decisions start karo.
        f(nums, j, subset, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        // Sorting duplicates ko adjacent laati hai, jisse unhe skip karna easy hota hai.
        sort(nums.begin(), nums.end());

        f(nums, 0, subset, result);
        return result;
    }
};

/*
TC: O(N * 2^N) worst case, including copying each subset into result.
SC: O(N) auxiliary space for recursion stack + current subset.
    Output storage is additional and can be O(N * 2^N).
*/
