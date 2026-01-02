class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1,st2;
        for(char c:s){
            if(c!='#') st1.push(c);
            else if(!st1.empty()){
                st1.pop();
        }
        }
        for(char c:t){
            if(c!='#') st2.push(c);
            else if(!st2.empty()){
                st2.pop();
        }
        }
        return st1==st2;
    }
};