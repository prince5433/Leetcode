class Solution {
public:
    string capitalizeTitle(string title) {
        
        /*
        Intuition:
        Har word ko process karna hai.

        Rule:
        size <= 2  -> pura lowercase
        size > 2   -> first uppercase, rest lowercase

        stringstream se words split kar rahe.
        */

        stringstream ss(title);
        string temp;
        string ans = "";

        // Traverse each word
        while (ss >> temp) {

            // Pehle pura lowercase
            for (char& ch : temp) {
                ch = tolower(ch);
            }

            /*
            Agar word bada hai
            to first letter capitalize
            */
            if (temp.size() > 2) {
                temp[0] = toupper(temp[0]);
            }

            // Build final string
            ans += temp + " ";
        }

        // Last extra space remove
        ans.pop_back();

        return ans;
    }
};

/*
Quick Idea:
Split words -> lowercase all ->
if size > 2 capitalize first.

Example:
"capiTalIze tHe titLe"

"Capitalize The Title"

TC: O(n)
(each char once)

SC: O(n)
(answer + stringstream)

Pattern:
String Processing
Simulation
*/