
class Solution {
public:
    bool isValid(string s) {

        // Agar length odd hai, toh har opening bracket ko closing bracket
        // ke saath pair nahi kar sakte. Isliye directly false.
        if(s.length()%2!=0) return false;

        stack<char> st;

        for(int i=0;i<s.size();i++){

            // Opening bracket mila toh stack mein push karo,
            // kyunki baad mein uska matching closing bracket aana chahiye.
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{//s[i]==')'||{||[

                // Closing bracket ke liye matching opening bracket zaroori hai.
                // Stack empty hai toh koi opening bracket available nahi hai.
                if(st.size()==0) return false;

                // Sabse recent unmatched opening bracket check karenge.
                char ch=st.top();

                // Current closing bracket aur stack top ka pair match karta hai
                // toh opening bracket ko pop karke pair complete kar do.
                if((s[i]==')'&& ch=='(') ||
                   (s[i]=='}'&& ch=='{') ||
                   (s[i]==']'&& ch=='[') ) {
                    st.pop();
                }

                // Agar pair match nahi karta, toh brackets ka order incorrect hai.
                else return false;
            }
        }

        // Saare characters process hone ke baad stack empty hai,
        // matlab har opening bracket ka matching closing bracket mil gaya.
        if(st.size()==0) return true;
        else return false;
    }
};
