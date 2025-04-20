class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int, int> freq;
        for(auto x : answers ){
            freq[x]++;
        }
        int total = 0;
        for(auto x : freq){
            int ele = x.first;
            int count = x.second;
            while(count > 0){
                total += ele + 1;
                count -= ele+1;
            }
        }
        return total;
    }
};