class Solution {
public:
    bool isDigitorialPermutation(int n) {
        
        // Precompute factorials of digits 0 to 9
        vector<int> fact(10,1);
        for(int i=1;i<10;i++){
            fact[i] = i * fact[i-1];   // i! = i × (i-1)!
        }
        
        int sum = 0;
        int temp = n;   // Store original number
        
        // Calculate sum of factorials of digits
        while(n > 0){
            int dig = n % 10;   // Extract last digit
            n /= 10;            // Remove last digit
            sum += fact[dig];   // Add factorial of digit
        }
        
        // Convert both numbers to string for digit comparison
        string s1 = to_string(temp);
        string s2 = to_string(sum);
        
        // If lengths differ, permutation is impossible
        if(s1.length() != s2.length()) return false;
        
        // Sort digits to compare frequency of digits
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        // If sorted digits match, some permutation forms a digitorial number
        return s1 == s2;
    }
};