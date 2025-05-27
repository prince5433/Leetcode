class Solution {
public:
    void f(int i,int n,vector<int>& result){
        if(i>n) return ;//base case
        if(i<=n and i!=0){//hamne 0 to n banay hai and hame 1 to n chahiye tahts why i!=0
            result.push_back(i);
        }
        for(int j=(i==0)? 1:0;j<=9;j++){
            f(10*i+j,n,result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>result;
        f(0,n,result);
        return result;
    }
};