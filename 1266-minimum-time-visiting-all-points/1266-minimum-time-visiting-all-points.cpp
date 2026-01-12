class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int sum=0;
        for(int i=0;i<n-1;i++){
            int first=points[i][0];
            int second=points[i][1];
            int diff1=abs(points[i+1][0]-first);
            int diff2=abs(points[i+1][1]-second);
             int mint=max(diff1,diff2);
             sum+=mint;
        }
        return sum;
    }
};