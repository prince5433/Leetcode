class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int n = arr.size();      // size of array
        int i = 0, j = 0;        // two pointers for sliding window
        int sum = 0;             // sum of current window
        int count = 0;           // number of valid subarrays
        
        while(j < n) {
            
            sum += arr[j];   // expand window by adding right element
            
            // when window size becomes exactly k
            if(j - i + 1 == k) {
                
                // check if average >= threshold
                // instead of (sum/k >= threshold),
                // we compare sum >= k * threshold to avoid division
                if(sum >= k * threshold)
                    count++;
                
                // before sliding window:
                // remove leftmost element from sum
                sum -= arr[i];
                
                // move left pointer forward
                i++;
            }
            
            // always move right pointer forward
            j++;
        }
        
        return count;   // total valid subarrays
    }
};