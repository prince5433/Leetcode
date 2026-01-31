class Solution {
public:
    int countElements(vector<int>& nums) {

        // minimum element nikaala
        int mini = *min_element(nums.begin(), nums.end());

        // maximum element nikaala
        int maxi = *max_element(nums.begin(), nums.end());

        // agar saare elements same hain
        // to koi bhi element strictly min aur max ke beech nahi hoga
        if (mini == maxi) 
            return 0;

        int cm = 0;   // minimum element ka count
        int cma = 0;  // maximum element ka count

        // min aur max ke occurrences count karo
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxi)
                cma++;
            else if (nums[i] == mini)
                cm++;
        }

        // total elements - (min ke count + max ke count)
        // = elements jo strictly min aur max ke beech hain
        return nums.size() - (cm + cma);
    }
};
