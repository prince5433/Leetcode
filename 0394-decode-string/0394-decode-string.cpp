class Solution {
public:
    string decodeString(string s) {
        stack <int> num;
        stack <string> str;
        int currnum=0;
        string curr="";
        for(char c:s){
            if(isdigit(c)){
                currnum=currnum*10+(c-'0');
            } else if(c=='['){
                num.push(currnum);
                str.push(curr);
                currnum=0;
                curr="";
            } else if(c==']'){
                int repeat=num.top();
                num.pop();
                string prevstr=str.top();
                str.pop();
                string temp="";
                for(int i=0;i<repeat;i++){
                    temp+=curr;
                }
                curr=prevstr+temp;
            } else{
                curr+=c;
            }
        }
        return curr;
        
    }
};