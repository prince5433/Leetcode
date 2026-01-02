class Solution {
public:
    string removeStars(string s) {
        string temp="";
        stack<char>st;
        for(char c:s){
            if(c!='*') st.push(c);
            else {
                st.pop();
            }
        }
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};