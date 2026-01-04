class Solution {
public:
    int check(int n){
        int sum = 0, cnt = 0;

        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                int d1 = i;
                int d2 = n / i;

                cnt++;
                sum += d1;

                if(d1 != d2){
                    cnt++;
                    sum += d2;
                }

                if(cnt > 4) return 0;   // zyada divisors → invalid
            }
        }

        return (cnt == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int n : nums){
            ans += check(n);
        }
        return ans;
    }
};
