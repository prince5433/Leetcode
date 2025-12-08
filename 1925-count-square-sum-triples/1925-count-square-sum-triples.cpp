class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
               int c=i*i+j*j;
               int d=sqrt(c);
               if(d*d==c&&d<=n) cnt++;
            }
        }
        return cnt*2;
    }
};