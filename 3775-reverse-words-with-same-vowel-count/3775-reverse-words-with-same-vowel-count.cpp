class Solution {
public:
    // Function to check if a character is a vowel
    bool isVowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }

    string reverseWords(string s) {

        // Step 1: Split the string into words
        stringstream ss(s);
        string temp;
        vector<string> ans;

        while(ss >> temp){
            ans.push_back(temp);
        }

        // Step 2: Count vowels in the first word
        int cnt = 0;
        for(char c : ans[0]){
            if(isVowel(c)) cnt++;
        }

        // Step 3: Reverse words having same vowel count
        // as the first word
        for(int i = 1; i < ans.size(); i++){
            int d = 0;
            for(char c : ans[i]){
                if(isVowel(c)) d++;
            }
            if(d == cnt){
                reverse(ans[i].begin(), ans[i].end());
            }
        }

        // Step 4: Join words back into a string
        string tem = "";
        for(int i = 0; i < ans.size(); i++){
            tem += ans[i];
            if(i != ans.size()-1) tem += " ";
        }

        return tem;
    }
};
