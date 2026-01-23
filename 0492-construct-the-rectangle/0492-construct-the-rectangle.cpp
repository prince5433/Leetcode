class Solution {
public:
    vector<int> constructRectangle(int area) {
         vector<int> ans;
         int finde=sqrt(area);
         for(int i=finde;i>=1;i--){
            int d1=i;
            int d2=area/i;
            if(d1*d2==area){
              ans.push_back(d1);
            ans.push_back(d2);
            break;
            }
         }
         sort(ans.rbegin(),ans.rend());
         return ans;
    }
};