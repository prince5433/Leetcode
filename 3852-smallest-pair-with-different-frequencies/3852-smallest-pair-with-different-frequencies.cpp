class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        
        vector<int> ans;                  // answer store karne ke liye
        
        int n = nums.size();
        
        // Agar elements 2 ya usse kam hain to valid pair possible nahi
        if(n <= 2) return {-1, -1};
        
        map<int,int> mp;                  // value -> frequency store karega
        
        // Frequency count
        for(int num : nums) 
            mp[num]++;
        
        // Smallest x lene ke liye sort kar rahe hain
        sort(nums.begin(), nums.end());
        
        ans.push_back(nums[0]);           // smallest value ko x maan liya
        int comp = nums[0];               // x store kiya
        
        int val = -1;                     // x ki frequency store karne ke liye
        
        // x ki frequency nikaal rahe hain
        for(auto it : mp){
            if(it.first == comp){
                val = it.second;
            }
        }
        
        // Ab smallest y find kar rahe hain
        // jiska frequency x se different ho
        for(auto it : mp){
            if(it.second != val){
                ans.push_back(it.first);  // valid y mil gaya
                return ans;
            }
        }
        
        // Agar koi valid pair nahi mila
        return {-1, -1};
    }
};