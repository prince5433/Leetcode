class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        // Step 1: Capacity ko sort karo (ascending order)
        sort(capacity.begin(), capacity.end());
        
        // Step 2: Total apples ka sum nikaalo
        int sum = 0;
        int n = apple.size();
        for(int i = 0; i < n; i++){
            sum += apple[i];
        }
        
        // Step 3: Ab largest capacity wale boxes uthao
        int m = capacity.size();
        int count = 0;   // kitne boxes use hue
        int csum = 0;    // boxes ki total capacity
        
        // Step 4: Piche se iterate (largest capacity se start)
        for(int i = m - 1; i >= 0; i--){
            csum += capacity[i];  // current box ki capacity add
            count++;              // ek box use ho gaya
            
            // Agar total capacity >= total apples
            if(csum >= sum){
                return count;     // minimum boxes mil gaye
            }
        }
        
        // Step 5: worst case (sab boxes use karne pade)
        return count;
    }
};
