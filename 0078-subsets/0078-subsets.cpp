
class Solution {
public:
    /*
    QUESTION: SUBSETS (LEETCODE 78)

    Given an array of DISTINCT integers, return all possible subsets.
    Example: nums = [1, 2]

    Output: [], [1], [2], [1, 2]

    INTUITION:
    Har element ke liye exactly 2 choices hain:
    1. PICK: Element ko current subset mein include karo.
    2. NOT PICK: Element ko exclude karo.

    N elements ke liye total 2^N subsets honge.
    */

    void f(vector<int>& nums, int idx, vector<int>& subset,
           vector<vector<int>>& result) {

        // BASE CASE: Har element ka decision ho chuka hai.
        // Current subset ek complete subset hai, ise save karo.
        if (idx == nums.size()) {
            result.push_back(subset);
            return;
        }

        // PICK: Current element include karke aage ke subsets explore karo.
        subset.push_back(nums[idx]);
        f(nums, idx + 1, subset, result);

        // UNDO: Element hatao, taaki NOT PICK branch mein woh absent rahe.
        subset.pop_back();

        // NOT PICK: Current element ko exclude karke aage badho.
        // Yahan duplicate skipping nahi chahiye, kyunki Subsets I mein
        // input distinct hota hai aur har possible subset required hai.
        f(nums, idx + 1, subset, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        // Sorting is problem ke liye necessary nahi hai;
        // subsets generate karne ke liye original order bhi kaam karega.
        f(nums, 0, subset, result);

        return result;
    }
};

/*
TC: O(N * 2^N), because 2^N subsets are generated and copied.
SC: O(N) auxiliary space for recursion stack + current subset.
    Output storage is additional: O(N * 2^N).
*/
