class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int ans = 0;
        int n = arr.size();

        // Fix starting index
        for(int i = 0; i < n; i++){

            // Fix ending index
            for(int j = i; j < n; j++){

                // Calculate length of subarray
                int len = j - i + 1;

                // Check if length is odd
                if(len % 2 != 0){

                    // Add all elements of this subarray
                    for(int k = i; k <= j; k++){
                        ans += arr[k];
                    }
                }
            }
        }

        return ans;
    }
};
