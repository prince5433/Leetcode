class Solution {
public:
    int GardenLastPoint;
    map<pair<int,int>,int>mp;
    int solve(int i,int maxEnd,vector<pair<int,int>>& range){
        if(i>=range.size()){// i put of range hai to
            if(maxEnd>=GardenLastPoint){//agr maxend bhr gya pura to koi tap nhi kholna
                return 0;
            } else{
                return 1e9;//agr nhi to int max not possible
            }
        }
        if(range[i].first>maxEnd){//beech me khali to not possible
            return 1e9;
        }
        if(mp.find({i,maxEnd})!=mp.end()) return mp[{i,maxEnd}];
        int not_open=solve(i+1,maxEnd,range);
        int open=1+solve(i+1,max(maxEnd,range[i].second),range);
        return mp[{i,maxEnd}]= min(not_open,open);
    }
   
    int minTaps(int n, vector<int>& ranges) {

        GardenLastPoint=n;
        vector<pair<int,int>> range;
        for(int i=0;i<ranges.size();i++){
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            range.push_back({start,end});
        }
        sort(range.begin(),range.end());
        int ans=solve(0,0,range);

        return ans>=1e9 ? -1 : ans;
    }
};