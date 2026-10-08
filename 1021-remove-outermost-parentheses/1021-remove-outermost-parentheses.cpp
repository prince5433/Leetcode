class Solution {
public:
    string removeOuterParentheses(string s) {

        string result;

        // WHY balance?
        // balance batata hai ki abhi kitne '(' open hain
        // jinka ')' abhi close nahi hua.
        //
        // balance = 0 → hum primitive ke outermost level par hain
        // balance > 0 → hum primitive ke andar hain.
        int balance = 0;


        for(int i = 0; i < s.size(); i++) {

            // Agar opening bracket hai
            if(s[i] == '(') {

                // WHY balance > 0?
                // Agar balance already > 0 hai,
                // iska matlab ye outermost '(' nahi hai.
                // Isliye ise result mein add karna hai.
                if(balance > 0) {
                    result += s[i];
                }

                // '(' open hua, so balance increase.
                balance++;

            }
            else {

                // ')' current '(' ko close karega.
                // Pehle balance decrease karna zaroori hai.
                balance--;

                // WHY balance > 0?
                // Agar ')' ke baad bhi balance > 0 hai,
                // to ye outermost ')' nahi hai.
                // Isliye ise result mein add karo.
                if(balance > 0) {
                    result += s[i];
                }
            }
        }

        return result;
    }
};