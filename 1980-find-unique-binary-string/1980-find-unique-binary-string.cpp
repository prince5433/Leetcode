class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        // Method 1: Cantor Diagonalization
        // Idea: Har string ke i-th index ko flip kar dete hain.
        // Isse jo nayi string banegi wo guaranteed kisi bhi existing string
        // se atleast ek position par different hogi.

        // string result="";
        // for(int i=0;i<nums.size();i++){
        //     result += (nums[i][i]=='0') ? '1' : '0';
        // }
        // return result;


        // Method 2: Binary → Decimal conversion + Missing number

        unordered_set<int> st;     // nums ke binary numbers ko decimal form me store karne ke liye
        int n = nums.size();

        for(const auto &num : nums){
            st.insert(stoi(num, nullptr, 2)); 
            // stoi(num, nullptr, 2) → binary string ko decimal integer me convert karta hai
        }

        // 0 se n tak check karte hain ki kaunsa number set me present nahi hai
        // n strings hain, to pigeonhole principle se ek number missing zaroor milega
        for(int i = 0; i <= n; i++){

            if(st.find(i) == st.end()){   // agar number set me nahi mila

                // decimal number ko binary string me convert karte hain
                string res = bitset<16>(i).to_string(); 

                // bitset 16-bit string deta hai (e.g., 0000000000000101)
                // hume sirf last n bits chahiye kyunki binary string ki length n honi chahiye
                return res.substr(16 - n);
            }
        }

        return "";
    }
};