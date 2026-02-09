class Solution {
public:
    // Check karta hai ki s1 aur s2 ko jodne par duplicate character to nahi ban raha
    bool hasCommon(string &s1, string& s2) {
        int arr[26] = {0}; // frequency array for characters
        
        // s1 ke characters mark karo
        for(char &ch : s1) {
            if(arr[ch-'a'] > 0) // agar pehle se present hai
                return true;    // duplicate mil gaya
            arr[ch-'a']++;
        }
        
        // s2 ke characters check karo
        for(char &ch : s2) {
            if(arr[ch-'a'] > 0) // agar s1 me already tha
                return true;    // duplicate banega
        }
        
        return false; // koi duplicate nahi
    }
    
    // memoization map
    unordered_map<string, int> mp;
    
    int solve(int idx, vector<string>& arr, string temp, int n) {
        // base case: end of array
        if(idx >= n)
            return temp.length(); // current string ka length return
        
        // agar state pehle se compute ho chuki hai
        if(mp.find(temp) != mp.end())
            return mp[temp];
        
        int include = 0;
        int exclude = 0;
        
        // agar current string lene se duplicate ban raha hai
        if(hasCommon(arr[idx], temp)) {
            // sirf skip kar sakte hain
            exclude = solve(idx+1, arr, temp, n);
        } else {
            // option 1: skip
            exclude = solve(idx+1, arr, temp, n);
           
            // option 2: include
            include = solve(idx+1, arr, temp += arr[idx], n);
        }
        
        // best result store karo
        return mp[temp] = max(include, exclude);
    }
    
    int maxLength(vector<string>& arr) {
        string temp = ""; // initial empty string
        mp.clear();       // memo clear
        int n = arr.size();
        
        // recursion start
        return solve(0, arr, temp, n);
    }
};
