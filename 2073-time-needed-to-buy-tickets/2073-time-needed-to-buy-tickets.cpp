class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       queue<pair<int,int>> qu;
       int n=tickets.size();
       for(int i=0;i<n;i++){
        qu.push({tickets[i],i});
       } 
       int time=0;
       while(!qu.empty()){
        int tkt=qu.front().first;
        int idx=qu.front().second;
        qu.pop();
        tkt--;
        time++;
        if(idx==k && tkt==0){
            return time;
        }
        if(tkt>0){
            qu.push({tkt,idx});
        }
       }
       return time;
    }
};