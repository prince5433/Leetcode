class Solution {
public:
 vector<vector<string>> ans;
 vector<string> path;
 bool isPallindrome(string s ,int l,int r){
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
 }
 void solve(int idx,string& s){
    //base case
    if(idx==s.size()){
        ans.push_back(path);
        return;
    }
    for(int j=idx;j<s.size();j++){
        if(isPallindrome(s,idx,j)){
            path.push_back(s.substr(idx,j-idx+1));//do
            solve(j+1,s);//explore
            path.pop_back();//undo
        }
    }
 }
    vector<vector<string>> partition(string s) {
        solve(0,s);
        return ans;
    }
};