class Solution {
public:
    int calculateScore(int a, int b) {
        int sba=__builtin_popcount(a);
        int sbb=__builtin_popcount(b);
        if(sba>=sbb) return sba*sbb;
        else return sbb/sba; 
    }
};