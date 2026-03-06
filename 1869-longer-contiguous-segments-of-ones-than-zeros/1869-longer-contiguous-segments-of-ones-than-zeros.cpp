class Solution {
public:
    bool checkZeroOnes(string s) {
        
        int noo = 0; // maximum length of consecutive 1s
        int noz = 0; // maximum length of consecutive 0s
        
        int n = s.size();
        
        int cno = 0; // current streak of 1s
        int cnz = 0; // current streak of 0s
        
        for(int i = 0; i < n; i++){
            
            if(s[i] == '1'){
                
                cno++;        // increase current 1 streak
                cnz = 0;      // reset 0 streak
                
                noo = max(cno, noo); // update max 1 streak
                
            } 
            else{
                
                cnz++;        // increase current 0 streak
                cno = 0;      // reset 1 streak
                
                noz = max(cnz, noz); // update max 0 streak
            }
        }

        // return true if longest 1 segment is greater than longest 0 segment
        return noo > noz;
    }
};