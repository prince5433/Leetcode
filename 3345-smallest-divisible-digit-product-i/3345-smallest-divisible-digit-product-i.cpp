class Solution {
public:
int product(int n){
    int prod = 1;        // start with 1, not 0
    while(n > 0){
        int digit = n % 10;   // extract last digit
        prod *= digit;        // multiply
        n /= 10;              // remove last digit
    }
    return prod;              // return the product
}

    int smallestNumber(int n, int t) {
        int i=n;
        while(true){
            int prod=product(i);
            if(prod%t==0) {
                return i;
            break;
            }
            i++;
         
        }
        return 0;
    }
};