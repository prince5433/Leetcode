class Solution {
public:
#define ll long long
bool can(long long t, int n, vector<int>& batteries) {
        long long total = 0;
        for (long long b : batteries) {
            total += min(b, t);
            if (total >= t * n) return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll lo=0;
        ll hi=accumulate(batteries.begin(),batteries.end(),0LL);
        ll ans=0;
        while(lo<=hi){
            ll mid=lo+(hi-lo)/2;
            if(can(mid,n,batteries)){
                ans=mid;
                lo=mid+1;
            } else {
                hi=mid-1;
            }
        }
        return ans;
    }
};