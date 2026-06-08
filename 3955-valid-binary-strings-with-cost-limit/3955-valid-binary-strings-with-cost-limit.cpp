class Solution {
public:
vector<string> ans;
void solve(int idx,int n,int k,int cost,char prev,string& temp){
    //base cases
    if(cost>k) return;
    if(idx==n){
        ans.push_back(temp);
        return;
    }
    //place 0;
    temp.push_back('0');
    solve(idx+1,n,k,cost,'0',temp);
    temp.pop_back();

    //place 1
    if(prev!='1'){
        temp.push_back('1');
        solve(idx+1,n,k,cost+idx,'1',temp);
        temp.pop_back();
    }
}
    vector<string> generateValidStrings(int n, int k) {
        string temp="";
        solve(0,n,k,0,'#',temp);
        return ans;
    }
};