class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        map<int,vector<int>> mp;
        for(int i=0;i<x.size();i++){
            mp[x[i]].push_back(y[i]);
        }
        vector<int> temp;
        for(auto &it:mp){
           auto& v=it.second;
            sort(v.rbegin(),v.rend());
            temp.push_back(v[0]);
        }
        if(temp.size()<3) return -1;
        sort(temp.rbegin(),temp.rend());
        return temp[0]+temp[1]+temp[2];
    }
};