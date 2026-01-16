class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();

        int i = 0, j = 0;
        int cntf = 0;
        int result = 0;

        // Case 1: F ko flip karke window ko all 'T' banane ki try
        // condition: window me F ki count <= k
        while (j < n) {
            if (answerKey[j] == 'F') cntf++;

            // agar F zyada ho gaye (k se), to window shrink karo
            while (cntf > k) {
                if (answerKey[i] == 'F') cntf--;
                i++;
            }

            // valid window length update
            result = max(result, j - i + 1);
            j++;
        }

        // reset pointers for second case
        i = 0; 
        j = 0;
        int cntt = 0;

        // Case 2: T ko flip karke window ko all 'F' banane ki try
        // condition: window me T ki count <= k
        while (j < n) {
            if (answerKey[j] == 'T') cntt++;

            // agar T zyada ho gaye (k se), to window shrink karo
            while (cntt > k) {
                if (answerKey[i] == 'T') cntt--;
                i++;
            }

            // valid window length update
            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};
