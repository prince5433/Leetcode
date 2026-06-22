class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int> diff(n+1,0);
        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int left=max(0,i-lights[i]);
                int right=min(n-1,i+lights[i]);
                diff[left]++;
                diff[right+1]--;
            }
        }
        vector<bool>isilluminated(n,false);
        int curr=0;;
        for(int i=0;i<n;i++){
            curr+=diff[i];
            if(curr>0) isilluminated[i]=true;
        }
        int newbulbs=0;
        for(int i=0;i<n;){
            if(!isilluminated[i]){
                newbulbs++;
                i+=3;
            } else {
                i++;
            }
        }
        return newbulbs;
    }
};