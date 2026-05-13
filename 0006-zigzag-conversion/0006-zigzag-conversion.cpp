class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int n=s.size();
        vector<string> rows(numRows);
        int row=0;
        int down=1;//1 means go down -1 means p go
        for(char c:s){
            rows[row]+=c;
            if(row==numRows-1){
                down=-1;
            }
            if(row==0){
                down=1;
            }
            row+=down;
        }
        string ans="";
        for(string& r:rows){
            ans+=r;
        }
        return ans;
    }
};