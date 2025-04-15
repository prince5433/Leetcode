class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        int ops=0;
        for(auto &it:mp){
           int freq=it.second;
           if(freq==1) return -1;
           ops+=(freq+2)/3;
        }
        return ops;
    }
};