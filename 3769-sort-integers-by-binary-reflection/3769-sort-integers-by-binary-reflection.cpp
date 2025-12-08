class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<long long,int>> v;

        for (int x : nums) {
            string s = bitset<32>(x).to_string();        // 32-bit binary
            s.erase(0, s.find_first_not_of('0'));        // remove leading zeros
            reverse(s.begin(), s.end());                 // reflection
            long long ref = stoll(s, nullptr, 2);       // convert to decimal
            v.push_back({ref, x});
        }

        sort(v.begin(), v.end());                        // sort by reflection
        vector<int> ans;
        for (auto &p : v) ans.push_back(p.second);      // extract numbers
        return ans;
    }
};
