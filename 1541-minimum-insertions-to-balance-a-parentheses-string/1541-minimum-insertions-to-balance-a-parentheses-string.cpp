class Solution {
public:
    int minInsertions(string s) {
        int cnt=0;
        int n=s.size();
        int result=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                cnt++;
                i++;
            } else{// => )
                if(cnt>0){//opeming braket tha
                    cnt--;
                } else{//agr nhi tha to ek open bracket add krenge
                result++;

                }
                if(i+1<n && s[i+1]==')'){
                    i+=2;
                } else {
                    result++;//add closing bracket
                    i++;
                }
            }
        }
        return result+ cnt*2;
    }
};