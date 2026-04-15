class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int mn=n;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int dist=abs(startIndex-i);
                int circular=(n-dist);
                mn=min(mn,min(dist,circular));
            }
        }
      if(mn==n) return -1;
      return mn;
    }
};