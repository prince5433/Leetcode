class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;

        for(string str : words){
            string temp = "";

            for(char c : str){
                if(c == separator){
                    // agar temp empty nahi hai to answer me daalo
                    if(!temp.empty()){
                        ans.push_back(temp);
                        temp = "";   // reset for next word
                    }
                } else {
                    temp += c;       // character add karo
                }
            }

            // last word ke liye (separator ke baad)
            if(!temp.empty()){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
