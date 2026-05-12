class Solution {
public:
    bool isPalindrome(int x) {
       int lastdigit=0;
       int r=0;
       int original = x; // Store the original value of x
       while(x!=0){
        if(x<0) return false;
        if((r>INT_MAX/10)||(r<INT_MIN/10)){
            return false;
        }
           r*=10;
           lastdigit=x%10; // Corrected variable name here
           r+=lastdigit;
           x/=10; // Corrected variable name here
       }
       if(r==original) return true; // Comparing with the original value
       else return false;
    }
};