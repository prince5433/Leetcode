class Solution {
public:
void generate(   vector<string>& ans,string s,int open,int close,int n){
    if(open==n && close==n){
        ans.push_back(s);
        return;
    }
    if(open<n)generate(ans,s+'(',open+1,close,n);//openuing call sirf tb lgegi jb count o f open < n hoga
    if(close<open)generate(ans,s+')',open,close+1,n);//closing call sirf tb lagegi jb count of closing < opening count hoga
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
         generate(ans,"",0,0,n);
         return ans;
    }
};