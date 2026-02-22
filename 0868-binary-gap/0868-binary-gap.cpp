class Solution {
public:
    int binaryGap(int n) {
        
        // convert number to binary string
        string temp = "";
        while(n > 0){
            temp += to_string(n % 2);
            n /= 2;
        }
        
        // reverse because we built it in reverse order
        reverse(temp.begin(), temp.end());
        
        int prev = -1;     // previous index of '1'
        int maxGap = 0;    // maximum distance
        
        for(int i = 0; i < temp.length(); i++){
            
            if(temp[i] == '1'){
                
                // if this is not the first '1'
                if(prev != -1){
                    maxGap = max(maxGap, i - prev);
                }
                
                // update previous
                prev = i;
            }
        }
        
        return maxGap;
    }
};