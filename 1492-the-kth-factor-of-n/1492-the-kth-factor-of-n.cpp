class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;

        // saare factors store karo
        for(int i = 1; i <= n; i++){
            if(n % i == 0){
                factors.push_back(i);
            }
        }

        // agar factors kam pad gaye
        if(factors.size() < k) return -1;

        // kth (1-indexed) factor return
        return factors[k - 1];
    }
};
