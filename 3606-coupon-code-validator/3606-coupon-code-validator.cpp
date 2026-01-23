class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        // businessLine ka fixed order define
        unordered_map<string,int> pr = {
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3}
        };

        // valid coupons store karenge as {priority, code}
        vector<pair<int,string>> v;

        for(int i = 0; i < (int)code.size(); i++){

            // inactive coupon -> invalid
            // empty code -> invalid
            // invalid businessLine -> invalid
            if(!isActive[i] || code[i].empty() || !pr.count(businessLine[i])) continue;

            // code me sirf alphanumeric ya '_' allowed hai
            bool ok = true;
            for(char c : code[i]){
                if(!(isalnum((unsigned char)c) || c == '_')){
                    ok = false;
                    break;
                }
            }

            // agar valid hai to store karo
            if(ok) v.push_back({pr[businessLine[i]], code[i]});
        }

        // sort by priority first, then code lexicographically (pair sorting auto)
        sort(v.begin(), v.end());

        // final answer me sirf codes return
        vector<string> ans;
        for(auto &x : v) ans.push_back(x.second);

        return ans;
    }
};
