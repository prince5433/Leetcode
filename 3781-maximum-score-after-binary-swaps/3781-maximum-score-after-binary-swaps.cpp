class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        
        // Max-Heap (Priority Queue) ka use:
        // Ye un sabhi 'nums[i]' ko store karega jahan s[i] == '0' hai.
        // Kyuki '1' peeche (left) move kar sakta hai, toh '0' wali jagah hamare liye 
        // ek "vacant seat" ki tarah hai.
        priority_queue<int> pq;
        long long ts = 0; // Total Score (long long for large sums)

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                // Case 1: Agar current character '0' hai.
                // Is index ki value ko PQ mein daal do, shayad aage koi '1' aaye 
                // jise yahan swap karke zyada score mil sake.
                pq.push(nums[i]);
            } 
            else {
                // Case 2: Agar current character '1' hai.
                
                // Check karo: Kya hamare paas peeche koi aisi '0' wali position hai 
                // jiski value (pq.top()) current value (nums[i]) se badi hai?
                if (!pq.empty() && pq.top() > nums[i]) {
                    // Agar haan, toh "Greedy" bano! Badi value ko score mein add karo.
                    ts += pq.top();
                    pq.pop(); // Woh '0' wala spot ab occupy ho gaya.
                    
                    // Current small value (nums[i]) ab '0' ki position par chali gayi hai.
                    // Isliye ise PQ mein push karenge taaki aage koi aur '1' ise use kar sake.
                    pq.push(nums[i]);
                } 
                else {
                    // Agar peeche koi badi value nahi mili, toh current '1' ko 
                    // apni hi jagah rehne do aur score mein add kar lo.
                    ts += nums[i];
                }
            }
        }
        
        return ts; // Final Maximum Score
    }
};