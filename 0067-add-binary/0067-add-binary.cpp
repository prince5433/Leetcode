class Solution {
public:

    // This function adds two bits (first, second) and a carry
    // It returns a pair:
    // first  -> result bit
    // second -> new carry
    pair<int,int> sum(int first, int second, int carry){

        // Case when carry is 0
        if(carry == 0){

            // 1 + 1 = 0 with carry 1
            if(first == 1 && second == 1)
                return {0, 1};

            // 0+0=0 carry=0 OR 1+0=1 carry=0 OR 0+1=1 carry=0
            return {first + second, 0};
        }
        else{ // carry == 1

            // 1+1+1 = 1 carry 1
            if(first == 1 && second == 1)
                return {1, 1};

            // 1+0+1=0 carry=1 OR 0+1+1=0 carry=1
            if(first == 1 || second == 1)
                return {0, 1};

            // 0+0+1 = 1 carry=0
            return {1, 0};
        }
    }


    string addBinary(string a, string b) {

        int n = a.size();
        int m = b.size();

        // Make both strings equal length by adding leading zeros
        if(n < m)
            a = string(m - n, '0') + a;

        else if(n > m)
            b = string(n - m, '0') + b;


        string totalSum = "";

        int i = a.size() - 1;
        int carry = 0;

        // Traverse from right to left (LSB to MSB)
        while(i >= 0){

            // Convert char to int
            int first = a[i] - '0';
            int second = b[i] - '0';

            // Add bits using helper function
            pair<int,int> res = sum(first, second, carry);

            // Update carry
            carry = res.second;

            // Add result bit at beginning
            totalSum = to_string(res.first) + totalSum;

            i--;
        }

        // If carry remains, add it at front
        if(carry)
            totalSum = '1' + totalSum;

        return totalSum;
    }
};
