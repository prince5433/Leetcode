class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        // answer vector jisme spiral order me cells store honge
        vector<vector<int>> ans;
        
        // total cells jitne visit karne hain
        int total = rows * cols;
        
        // spiral me step length initially 1 hoti hai
        int len = 1;
        
        // 4 directions define kar rahe hain in spiral order:
        // right → down → left → up
        vector<vector<int>> dirs = {
            {0,1},   // move right → column increase
            {1,0},   // move down  → row increase
            {0,-1},  // move left  → column decrease
            {-1,0}   // move up    → row decrease
        };
        
        // current position ko starting position se initialize karo
        int r = rStart;
        int c = cStart;
        
        // starting cell ko answer me add karo
        ans.push_back({r, c});
        
        // jab tak sab cells visit nahi ho jate tab tak spiral continue karo
        while(ans.size() < total){
            
            // 4 directions me movement karenge
            for(int d = 0; d < 4; d++){
                
                // current direction me len steps move karna hai
                for(int i = 0; i < len; i++){
                    
                    // next cell me move karo according to direction
                    r += dirs[d][0];
                    c += dirs[d][1];
                    
                    // agar current cell grid ke andar hai to answer me add karo
                    if(r >= 0 && r < rows && c >= 0 && c < cols){
                        ans.push_back({r, c});
                    }
                }
                
                // important logic:
                // spiral expand hota hai after every 2 directions
                
                // after DOWN and UP, increase step length
                // pattern:
                // right(1), down(1) → len becomes 2
                // left(2), up(2) → len becomes 3
                
                if(d == 1 || d == 3){
                    len++;
                }
            }
        }
        
        // final spiral order return karo
        return ans;
    }
};
