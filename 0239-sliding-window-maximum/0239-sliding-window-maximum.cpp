class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if(k == 1) return nums;           // if window size is 1, every element is itself the maximum
        
        int n = nums.size();              // size of the array
        
        deque<int> dq;                   // deque to store indices of useful elements
        vector<int> ans;                 // result vector to store maximum of each window
        
        for(int i = 0; i < n; i++){
            
            // remove elements from back which are smaller than current element
            // because they will never be the maximum in future windows
            while(dq.size() > 0 && nums[i] > nums[dq.back()])
                dq.pop_back();
            
            dq.push_back(i);             // push current index into deque
            
            int j = i - k + 1;           // starting index of the current window
            
            // remove indices which are outside the current window
            while(dq.front() < j)
                dq.pop_front();
            
            // when the first window is formed
            if(i >= k - 1)
                ans.push_back(nums[dq.front()]); // front of deque holds index of max element
        }
        
        return ans;                      // return all sliding window maximums
    }
};