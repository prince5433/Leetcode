class Solution {
public:
    pair<int,int> sum(int first, int second, int carry){
        if(carry == 0){
            if(first == 1 && second == 1) return {0, 1};
            return {first+second, 0};
        } else { //carry == 1
            if(first == 1 && second == 1) return {1, 1};
            if(first == 1 || second == 1) return {0, 1};
            return {1, 0};
        }
    }

    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        if(n<m) a = string(m-n,'0') + a; // making size equal
        else if(n>m) b = string(n-m,'0') + b;

        string totalSum = "";
        int i = a.size()-1, carry = 0;

       while(i>=0){
            int first = a[i] - '0'; //char to int
            int second = b[i] - '0';
            pair<int, int> res = sum(first,second,carry);
            carry = res.second;
            totalSum = to_string(res.first) + totalSum;
            i--;
        }
        if (carry) totalSum = '1' + totalSum;// add any remaining carry at last
        return totalSum;
    }
};