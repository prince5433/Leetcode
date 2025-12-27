class Solution {
public:
    string generateTheString(int n) {
        string temp="";
        if(n%2==0){
            for(int i=0;i<n-1;i++){
                temp+='a';
            }
            temp+='b';
        } else {
            for(int i=0;i<n;i++){
                temp+='a';
            }
        }
        return temp;

    }
};