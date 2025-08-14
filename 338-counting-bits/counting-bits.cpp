class Solution {
public:
    vector<int> countBits(int n) {
        // vector<int> result;
        // for(int i=0;i<=n;i++){
        //     result.push_back(__builtin_popcount(i));
        // }
        // return result;


        //approach 2
        vector<int> result(n+1);
        result[0]=0;
        for(int i=1;i<=n;i++){
            if(i%2!=0){
                result[i]=result[i/2]+1;
            } else {
                result[i]=result[i/2];
            }
        }
        return result;
    }
};