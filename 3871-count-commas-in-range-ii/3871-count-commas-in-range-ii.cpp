class Solution {
public:
    long long countCommas(long long n) {
        long long tc=0;
        // if(n>=1000){
        //     tc+=n-1000+1;
        // }
        // if(n>=1000000){
        //     tc+=n-1000000+1;
        // }
        // if(n>=1000000000){
        //     tc+=n-1000000000+1;
        // }
        // if(n>=1000000000000){
        //     tc+=n-1000000000000+1;
        // }
        // if(n>=1000000000000000){
        //     tc+=n-1000000000000000+1;
        // }
        // return tc;

        for(long long i=1000;i<=n;i*=1000){
            tc+=n-i+1;
            if(i>1e12) break;
        }
        return tc;
    }
};