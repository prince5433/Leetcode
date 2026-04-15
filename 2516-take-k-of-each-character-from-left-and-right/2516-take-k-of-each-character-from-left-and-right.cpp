class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        
        // 🔹 Step 1: Har character ki total frequency count karo
        int c_a = 0, c_b = 0, c_c = 0;
        for(char c : s) {
            if(c == 'a') c_a++;
            else if(c == 'b') c_b++;
            else c_c++;
        }

        // 🔹 Step 2: Pehle hi check kar lo ki kya k-characters milna possible bhi hai?
        if(c_a < k || c_b < k || c_c < k) return -1;

        /* 💡 HUMARI STRATEGY: 
           Hum 'c_a', 'c_b', 'c_c' ko "Window ke BAHAR" ke characters ki tarah treat karenge.
           Jab window (j) badhega, toh bahar ke count kam honge.
        */
        int i = 0; // Left pointer (window start)
        int j = 0; // Right pointer (window end)
        int max_window = 0; 

        // 🔹 Step 3: Sliding Window Scan
        while(j < n) {
            // Character window ke ANDAR gaya, matlab bahar ka count kam hua
            if(s[j] == 'a') c_a--;
            else if(s[j] == 'b') c_b--;
            else if(s[j] == 'c') c_c--;

            /* 🔥 THE RED ALERT:
               Agar kisi bhi char ka count 'k' se kam ho gaya (bahar ki taraf), 
               toh window ko left (i) se shrink karo taaki wo char bahar wapas aa jaye.
            */
            while(i <= j && (c_a < k || c_b < k || c_c < k)) {
                if(s[i] == 'a') c_a++;
                else if(s[i] == 'b') c_b++;
                else if(s[i] == 'c') c_c++;
                i++; // Window ka left boundary aage badhao
            }

            // Sabse badi window jo condition satisfy kare, use update karo
            // Formula: current_window_size = j - i + 1
            max_window = max(max_window, j - i + 1);
            j++;
        }

        /* 🔹 FINAL CALCULATION:
           Total Length - Sabse badi window jo hum chhod sakte hain
           Answer = $$n - max\_window$$
        */
        return n - max_window;
    }
};