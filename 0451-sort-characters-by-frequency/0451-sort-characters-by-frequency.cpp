class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Count frequency of each character
        map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }

        // Step 2: Max-heap (frequency, character)
        // Highest frequency character will come on top
        priority_queue<pair<int,char>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        // Step 3: Build the result string
        string ans = "";

        // Take characters from heap in decreasing frequency order
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int count = top.first;   // frequency
            char ch = top.second;    // character

            // Append character 'count' times
            ans.append(count, ch);
        }

        return ans;
    }
};
