class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //method 1
        // string result="";
        // //cantor diagonalization 
        // for(int i=0;i<nums.size();i++){
        //     result+=(nums[i][i]=='0')?'1':'0';
        // }
        // return result;

        //method 2 
        unordered_set<int> st;
        int n=nums.size();
        for(const auto&num:nums){
            st.insert(stoi(num, nullptr, 2));//binary to decimal
        }
        for(int i=0;i<=n;i++){// n tak chala rhe kyoki n size me se ek to hoga hi jo kisis me present nhi hoga
            if(st.find(i)==st.end()){
                string res = bitset<16>(i).to_string(); // Convert to binary string of 16 bits
                return res.substr(16 - n); // Extract the last n bits
            }
        }
        return "";
    }
};