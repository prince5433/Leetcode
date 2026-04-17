class Solution {
public:


// 🔁 Function to reverse digits of a number
int reverseNum(int x) {
    int rev = 0;  
    // rev stores the reversed number being built

    while(x) {
        // take last digit of x and add to rev
        rev = rev * 10 + x % 10;

        // remove last digit from x
        x /= 10;
    }

    return rev;  
    // final reversed number
}

int minMirrorPairDistance(vector<int>& nums) {

    unordered_map<int,int> mp;
    // map: value -> latest index
    // BUT here we store reversed values as keys

    int ans = INT_MAX;
    // initialize answer with very large value
    // so we can minimize later

    for(int i = 0; i < nums.size(); i++) {

        // 🔍 Step 1: Check if current number already exists in map
        if(mp.count(nums[i])) {
            // if yes → it means some previous number's reverse
            // was equal to this nums[i]

            ans = min(ans, i - mp[nums[i]]);
            // update minimum distance
            // (current index - previous matching index)
        }

        // 🔁 Step 2: Compute reverse of current number
        int rev = reverseNum(nums[i]);

        mp[rev] = i;
        // store reversed number as key
        // so future elements can match directly
        // also we overwrite to keep latest index
    }

    return ans == INT_MAX ? -1 : ans;
    // if no valid pair found → return -1
    // otherwise return minimum distance
}


};
