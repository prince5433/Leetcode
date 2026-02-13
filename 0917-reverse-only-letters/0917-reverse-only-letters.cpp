class Solution {
public:
    string reverseOnlyLetters(string s) {

        int n = s.size();

        // Two pointers
        int i = 0;
        int j = n - 1;

        while(i <= j){

            // If both are alphabets → swap
            if(isalpha(s[i]) && isalpha(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }

            // If left is not alphabet → move left pointer
            else if(!isalpha(s[i]))
                i++;

            // If right is not alphabet → move right pointer
            else if(!isalpha(s[j]))
                j--;
        }

        return s;
    }
};
