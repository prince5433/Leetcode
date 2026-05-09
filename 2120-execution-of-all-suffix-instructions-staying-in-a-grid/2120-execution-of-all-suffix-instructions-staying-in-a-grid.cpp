class Solution {
public:
bool isValid(int i,int j,int n){
    if(i<n && j<n && i>=0 && j>=0) return true;
    return false;
}
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m=s.size();
        vector<int> ans;
       
       for(int k=0;k<m;k++){
        int i=startPos[0];
        int j=startPos[1];
         int steps=0;
         for(int idx=k;idx<m;idx++){
            char ch=s[idx];
            if(ch=='R')j++;
            else if(ch=='L')j--;
            else if(ch=='U')i--;
            else i++;
            if(!isValid(i,j,n)){
                break;
            }
            steps++;
         }
         ans.push_back(steps);
       }
       return ans;
    }
};