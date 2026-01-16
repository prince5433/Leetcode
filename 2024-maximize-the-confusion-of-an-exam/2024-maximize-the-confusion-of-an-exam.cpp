class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int i = 0, j = 0;
        int res = 0;

        unordered_map<char,int> mp; 
        // mp['T'] = current window me T count
        // mp['F'] = current window me F count

        while (j < n) {
            // right pointer add karo
            mp[answerKey[j]]++;

            // min(T,F) = window me jo minority character hai
            // us minority ko flip karke window ko all same banaya ja sakta hai
            // agar minority > k ho gaya => k flips se possible nahi => shrink window
            while (min(mp['T'], mp['F']) > k) {
                mp[answerKey[i]]--;
                i++;
            }

            // valid window ka max length update
            res = max(res, j - i + 1);
            j++;
        }

        return res;
    }
};
