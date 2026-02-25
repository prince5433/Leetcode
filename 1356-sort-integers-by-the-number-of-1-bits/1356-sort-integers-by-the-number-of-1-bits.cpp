class Solution {
public:
    
    // custom comparator function
    static bool compare(int a, int b) {
        
        // agar dono numbers me set bits equal hain
        if (__builtin_popcount(a) == __builtin_popcount(b)) {
            return a < b;   // normal ascending order
        }
        
        // warna jis number me kam set bits hain wo pehle aayega
        return __builtin_popcount(a) < __builtin_popcount(b);
    }

    vector<int> sortByBits(vector<int>& arr) {
        
        // STL sort with custom comparator
        sort(arr.begin(), arr.end(), compare);
        
        return arr;
    }
};