class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnta=0,cntb=0;
        int n=colors.size();
        if(n<3) return false;
        for(int i=1;i<n-1;i++){
            if(colors[i]==colors[i-1] && colors[i]==colors[i+1]){
               if(colors[i]=='A') {
                cnta++;
               } else if(colors[i]=='B') {
                cntb++;
               }
            }
        }
        return cnta>cntb;
    }
};