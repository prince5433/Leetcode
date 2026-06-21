class Solution {
public:
    int maxDistance(string moves) {
        int netx=0;
        int nety=0;
        int under=0;
        for(char c:moves){
            if(c=='U') nety++;
            else if(c=='L') netx--;
            else if(c=='R') netx++;
            else if(c=='D')nety--;
            else under++;
        }
        int abso=abs(netx)+abs(nety)+under;
        return abso;
    }
};