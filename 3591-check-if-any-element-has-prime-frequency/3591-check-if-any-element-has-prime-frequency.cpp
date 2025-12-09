class Solution {
public:

    // Function to check whether a number is prime or not
    bool isPrime(int n){
        if(n == 1) return false;                 // 1 prime nahi hota

        // Prime check only till sqrt(n) for high performance
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){                      // koi divisor mil gaya → prime nahi
                return false;
            }
        }
        return true;                             // koi divisor nahi → prime
    }

    // Main function: check whether ANY number's frequency is prime
    bool checkPrimeFrequency(vector<int>& nums) {

        unordered_map<int,int> mp;               // element → frequency map

        // Counting frequency of each element
        for(int num : nums)
            mp[num]++;                           // har number ka count badhaya

        // Iterate through the map to check its frequencies
        for(auto it : mp){
            // agar kisi bhi element ka frequency prime nikla → true
            if(isPrime(it.second)) {
                return true;                     // prime frequency mil gaya
                break;                           // (optional) loop stop
            }
        }

        return false;                            // koi frequency prime nahi thi
    }
};
