class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size();        // total soldiers
        int teams = 0;                // valid teams ka count
        
        // j ko middle soldier maan rahe hain
        for(int j = 1; j < n-1; j++){
            
            int csl = 0;  // count smaller on left
            int csr = 0;  // count smaller on right
            int cll = 0;  // count larger on left
            int clr = 0;  // count larger on right
            
            // j ke left side ke soldiers check karo
            for(int i = 0; i < j; i++){
                
                // agar left soldier ka rating chhota hai
                if(rating[i] < rating[j]){
                    csl++;
                } 
                // agar left soldier ka rating bada hai
                else if(rating[i] > rating[j]){
                    cll++;
                }
            }
            
            // j ke right side ke soldiers check karo
            for(int k = j + 1; k < n; k++){
                
                // agar right soldier ka rating bada hai
                if(rating[j] < rating[k]){
                    clr++;
                } 
                // agar right soldier ka rating chhota hai
                else if(rating[j] > rating[k]){
                    csr++;
                }
            }
            
            // valid teams count:
            // increasing teams → smaller left * larger right
            // decreasing teams → larger left * smaller right
            teams += (csl * clr) + (csr * cll);
        }
        
        return teams;   // total valid teams
    }
};