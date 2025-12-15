class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n=batteryPercentages.size();
        int cnt=0;
        int i=0;
        while(i<n){
            if(batteryPercentages[i]>0){
                cnt++;
                for(int j=i+1;j<n;j++){
                    batteryPercentages[j]=max(0,batteryPercentages[j]-1);
                }
            } 
            i++;
        }
        return cnt;
    }
};