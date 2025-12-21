class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n=nums.size();
        priority_queue<int>pq;
        long long ts=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                pq.push(nums[i]);
            } else{
                if(!pq.empty()&& pq.top()>nums[i]){
                    ts+=pq.top();
                    pq.pop();
                    pq.push(nums[i]);;
                }
                else{
                    ts+=nums[i];
            }
            } 
        
        }
        return ts;
    }
};