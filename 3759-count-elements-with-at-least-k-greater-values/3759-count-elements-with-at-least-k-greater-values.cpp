class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        
        // 1. Array ko sort kar rahe hain taaki binary search (upper_bound) kaam kar sake
        // Isse saare chote elements left mein aur bade elements right mein aa jayenge
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            int el = nums[i];
            
            // 2. upper_bound() returns an iterator to the first element 'strictly greater' than 'el'
            // Hum binary search use kar rahe hain taaki fast pata chale ki bade elements kahan se shuru ho rahe hain
            auto it = upper_bound(nums.begin(), nums.end(), el);
            
            // 3. Iterator ko index mein convert kar rahe hain
            int pos = it - nums.begin();
            
            // 4. 'pos' ke baad wale saare elements 'el' se bade hain.
            // Toh unka total count hoga (total size - current position index)
            int greater = n - pos;
            
            // 5. Agar strictly greater elements ka count 'k' ya usse zyada hai, 
            // toh yeh element 'qualified' hai
            if(greater >= k) {
                cnt++;
            }
        }
        
        // 6. Total qualified elements return kar rahe hain
        return cnt;
    }
};