class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size(); // total elements in array

        vector<int> ans(queries.size()); // final answers for each query

        unordered_map<int, vector<int>> mp; 
        // map: value -> all indices where this value appears

        // Step 1: build map
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i); 
            // store index of each value
        }

        // Step 2: process each query
        for(int i = 0; i < queries.size(); i++){

            int idx = queries[i]; // current query index
            int value = nums[idx]; // value at that index

            vector<int>& vec = mp[value]; // all indices where this value occurs
            int size = vec.size();

            // if only one occurrence → no answer
            if(size == 1){
                ans[i] = -1;
                continue;
            }

            // Step 3: find position of idx in vec using binary search
            auto it = lower_bound(vec.begin(), vec.end(), idx);
            int pos = it - vec.begin();

            int res = INT_MAX; // store minimum distance

            // Step 4: RIGHT neighbor (next occurrence)
            int right = vec[(pos + 1) % size]; 
            // circular: last element ka next = first element

            int d = abs(idx - right); // direct distance
            int circularDist = n - d; // circular wrap distance

            res = min({res, d, circularDist}); // take best

            // Step 5: LEFT neighbor (previous occurrence)
            int left = vec[(pos - 1 + size) % size]; 
            // +size to avoid negative index

            d = abs(idx - left); 
            circularDist = n - d;

            res = min({res, d, circularDist});

            // Step 6: store answer
            ans[i] = res;
        }

        return ans; // final result
    }
};