class Solution {
public:
    bool checkValidString(string s) {
        int oc=0;
        int cc=0;
        int length=s.length()-1;
        for(int i=0;i<=length;i++){
            if(s[i]=='(' || s[i]=='*'){
                oc++;
            } else{
                oc--;
            }
            if(s[length-i]==')' || s[length-i]=='*'){
                cc++;
            } else{
                cc--;
            }
            if(oc<0 || cc<0) return false;
        }
        return true;
    }
};