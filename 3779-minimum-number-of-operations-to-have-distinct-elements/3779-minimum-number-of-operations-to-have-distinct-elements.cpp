class Solution {
public:
    int minOperations(vector<int>& nums) {
       int n = nums.size();
        unordered_set<int> st;

        // Step 1: Peeche se check karna shuru karein (Right to Left)
        // Hum ye dekh rahe hain ki array ka "kaunsa suffix" (end part) already distinct hai.
        for (int i = n - 1; i >= 0; i--) {
            
            // Step 2: Agar current element set mein pehle se hai, 
            // iska matlab index 'i' par ek duplicate mil gaya hai.
            if (st.count(nums[i])) {
                
                // Step 3: Agar 'i' index par duplicate hai, toh humein 
                // index 0 se lekar index 'i' tak ke saare elements hatane honge.
                // Total elements to remove = (i + 1)
                
                // Kyunki har operation mein 3 elements remove hote hain:
                // Operations = ceil((i + 1) / 3)
                // Integer division mein iska shortcut formula hota hai: (i / 3) + 1
                return (i / 3) + 1;
            }
            
            // Step 4: Agar duplicate nahi hai, toh use set mein daal dein
            st.insert(nums[i]);
        }

        // Step 5: Agar pura loop khatam ho gaya aur koi duplicate nahi mila,
        // iska matlab array already distinct hai.
        return 0;
    }
};