class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int sum=0;
        int n=apple.size();
        for(int i=0;i<n;i++){
            sum+=apple[i];
        }
        int m=capacity.size();
        int count=0;
        int csum=0;
        for(int i=m-1;i>=0;i--){
            csum+=capacity[i];
            count++;
            if(csum>=sum){
                return count;
            }
        }
        return count;
    }
};