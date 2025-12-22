class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        double five=(n*5)/100;
        double ts=0;
        for(int i=0+five;i<n-five;i++){
            ts+=arr[i];
        }
        return ts/(n-(2*five));
    }
};