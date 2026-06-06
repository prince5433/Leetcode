class Solution {
public:
    bool consecutiveSetBits(int n) {
        string binary = bitset<32>(n).to_string();

        int cnt=0;
        for (int i = 1; i < 32; i++) {
            if (binary[i] == '1' && binary[i - 1] == '1')
                cnt++;
        }

        return cnt==1;
    }
};