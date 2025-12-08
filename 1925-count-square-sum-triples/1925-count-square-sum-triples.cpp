class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;

        // Iterate for all possible values of 'i' and 'j'
        // such that i < j (unique combinations)
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){

                // Compute c = i^2 + j^2
                int c = i * i + j * j;

                // Find sqrt(c) to check if c is a perfect square
                int d = sqrt(c);

                // If d^2 == c  AND  d <= n,
                // then (i, j, d) is a valid Pythagorean triple
                if(d * d == c && d <= n) 
                    cnt++;
            }
        }

        // Multiply by 2 because (i, j, d) and (j, i, d) are both valid
        return cnt * 2;
    }
};
