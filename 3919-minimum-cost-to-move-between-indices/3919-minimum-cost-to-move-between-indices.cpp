class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        // INTUITION: Hum har kadam pe baar-baar cost calculate nahi kar sakte (TLE aa jayega).
        // Isliye hum pehle hi "Index 0 se aage badhne ka" (l2r) aur 
        // "Last Index se peeche aane ka" (r2l) total cost nikal ke rakh lenge.
        // Array 'long long' ka hai taaki values add karte time integer ki limit (overflow) cross na ho.
        vector<long long> l2r(n, 0);
        vector<long long> r2l(n, 0);
        
        // ==========================================
        // 1. L2R (LEFT TO RIGHT) AAGE BADHNE KA COST
        // ==========================================
        l2r[0] = 0; // 0 se 0 pe rehne ka cost 0
        // INTUITION: Index 0 ka ek hi padosi hai (Index 1). Toh wahi uska 'closest' hoga.
        // Jab bhi closest pe jaate hain, special cost sirf 1 lagta hai.
        if(n > 1) l2r[1] = 1; 
        
        for(int i = 1; i < n - 1; i++){
            long long distleft = (long long)nums[i] - nums[i-1];   // Peeche wale neighbor se doori
            long long distright = (long long)nums[i+1] - nums[i];  // Aage wale neighbor se doori
            
            // INTUITION: Problem kehti hai jo kareeb hai wo 'closest' hai.
            // Agar right wala neighbor zyada kareeb hai (distright < distleft), 
            // toh right mein jump lagane ka special discount (cost = 1) milega.
            if(distright < distleft){
                l2r[i+1] = l2r[i] + 1;
            }
            // Warna, agar right wala door hai (ya barabar hai), toh closest left wala hoga.
            // Iska matlab hum right mein normal move kar rahe hain, toh cost unka difference hoga.
            else {
                l2r[i+1] = l2r[i] + distright;
            }
        }
        
        // ==========================================
        // 2. R2L (RIGHT TO LEFT) PEECHE AANE KA COST
        // ==========================================
        r2l[n-1] = 0; // Last index pe khade rehne ka cost 0
        // INTUITION: Last index ka bhi ek hi padosi hai (Second Last). Wahi uska 'closest' hoga.
        if(n > 1) r2l[n-2] = 1; 
        
        for(int i = n - 2; i > 0; i--){
            long long distleft = (long long)nums[i] - nums[i-1];
            long long distright = (long long)nums[i+1] - nums[i];
            
            // INTUITION: Tie-breaker rule - agar dono neighbor barabar doori pe hain, 
            // toh chote index (left wale) ko 'closest' maanna hai.
            // Isliye yahan '<=' lagaya hai. Agar left wala kareeb ya barabar hai, 
            // toh peeche (left) aane ka special cost sirf 1 lagega.
            if(distleft <= distright){
                r2l[i-1] = r2l[i] + 1;
            }
            // Warna peeche aane ke liye normal difference wala cost add karenge.
            else {
                r2l[i-1] = r2l[i] + distleft; 
            }
        }
        
        // ==========================================
        // 3. QUERIES KO O(1) TIME MEIN SOLVE KARNA
        // ==========================================
        vector<int> ans;
        for(auto &q : queries){
            int u = q[0], v = q[1];
            
            // INTUITION: Agar u se v jaana hai aur v aage hai (u < v), 
            // toh L2R array use karo. Destination ke cost mein se Source ka cost hata do.
            if(u < v){
                ans.push_back((int)(l2r[v] - l2r[u]));
            } 
            // Agar u se v jaana hai aur v peeche hai (u > v), 
            // toh R2L array use karo. Destination minus Source.
            else if(u > v){
                ans.push_back((int)(r2l[v] - r2l[u]));
            }
            // Agar Source aur Destination same hain (u == v)
            else {
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};