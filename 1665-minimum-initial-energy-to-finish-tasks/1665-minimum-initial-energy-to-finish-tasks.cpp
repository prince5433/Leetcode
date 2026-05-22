class Solution {
public:
bool isPossible(vector<vector<int>>& tasks,int mid){
    for(auto &task:tasks){
        int actual=task[0];
        int minimum=task[1];
        if(mid<minimum) return false;
        mid-=actual;
    }
    return true;
}
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        auto lambda =[](auto& task1,auto & task2){
            int diff1=task1[1]-task1[0];
            int diff2=task2[1]-task2[0];

            return diff1>diff2;
        };
        sort(tasks.begin(),tasks.end(),lambda);
        
        int lo=0;
        int hi=1e9;
        int ans=INT_MAX;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isPossible(tasks,mid)){
                ans=mid;
                hi=mid-1;
            } else{
                lo=mid+1;
            }
        }
        return ans;
    }
};