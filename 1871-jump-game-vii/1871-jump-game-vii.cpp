class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
      int n=s.size();
      queue<int> qu;
      qu.push(0);
      int farthest=0;
      while(!qu.empty()){
        int idx=qu.front();
        qu.pop();
        int start=max(idx+minJump,farthest);
        int end=min(idx+maxJump,n-1);
        for(int j=start;j<=end;j++){
            if(s[j]=='0'){
                if(j==n-1) return true;
                qu.push(j);
            }
        }
        farthest=end+1;
      }
      return n==1;
    }
};