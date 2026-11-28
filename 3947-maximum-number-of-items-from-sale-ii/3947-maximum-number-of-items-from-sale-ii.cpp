class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // STEP 1: Frequency array aur sabse sasta price (minPrice) nikalo
        // Intuition: Constraints ke hisaab se factor <= n hai, isliye array size (n+1) kaafi hai.
        // minPrice isliye chahiye kyunki jab free offers khatam ho jayenge,
        // tab bache hue budget se hum sirf sabse sasta item hi khareedenge (Value-1 deal).
        vector<int> cnt(n + 1, 0);
        long long minPrice = 1e18;

        for (auto& it : items) {
            cnt[it[0]]++;
            minPrice = min(minPrice, (long long)it[1]);
        }

        // STEP 2: Har factor 'f' ke kitne multiples array mein hain, wo count karo
        // Intuition: Agar factor 'f', kisi 'm' ko divide karta hai, toh 'm' factor 'f' ka multiple hoga.
        // Harmonic series (n + n/2 + n/3 + ...) ki wajah se ye nested loop sirf O(N log N) mein chalega.
        vector<int> multiples(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            if (cnt[f] == 0) continue; // Optimization: jo factor exist hi nahi karta, usko skip karo
            
            // FIX: m += f (har step par f ka agla multiple: f, 2f, 3f...)
            for (int m = f; m <= n; m += f) {
                multiples[f] += cnt[m];
            }
        }

        // STEP 3: Value-2 deals (Buy 1 Get 1 Free) ki list banao
        // Intuition: Har item 'i' ki pehli 'gain' copies khareedne par 1 paid + 1 free = 2 items milte hain.
        // 'multiples[f] - 1' isliye kiya kyunki item khud ko free nahi de sakta (i != j).
        vector<pair<long long, int>> deals;
        for (auto& it : items) {
            int f = it[0];
            long long p = it[1];
            int gain = multiples[f] - 1;
            
            if (gain > 0) {
                deals.push_back({p, gain}); // {is deal ka price, kitni baar ye deal mil sakti hai}
            }
        }

        // STEP 4: Saari Value-2 deals ko price ke hisaab se sort karo (sasti deal pehle)
        // Intuition: Greedy approach - kam paiso mein zyada items lene ke liye sabse sasti deals pehle lenge.
        sort(deals.begin(), deals.end());

        long long ans = 0;
        long long remBudget = budget;

        // STEP 5: Batch mein sasti Value-2 deals khareedo
        for (auto& [price, gain] : deals) {
            // GOLDEN CONDITION:
            // Agar 1 Value-2 deal (2 items) ka price, 2 sabse saste single items (2 * minPrice) se
            // zyada ya barabar hai, toh ye deal mehangi hai! Aage saari deals aur mehangi hongi, so break.
            if (price >= 2 * minPrice) break;

            // Ek-ek karke khareedne ki jagah seedha batch mein khareedo:
            // Ya toh is item ki saari 'gain' copies le lo, ya jitni bache hue budget mein aa sakein.
            long long canBuy = min((long long)gain, remBudget / price);
            
            ans += canBuy * 2;           // Har copy se 2 items mile (1 khareeda + 1 free)
            remBudget -= canBuy * price; // Kharcha budget se minus karo
        }

        // STEP 6: Leftover Budget ka use
        // Intuition: Saari sasti Value-2 deals khatam ho gayi (ya budget kam pad gaya).
        // Ab jo bhi paise bache hain, unse sabse sasta item (minPrice) jitni baar aa sake le lo.
        ans += remBudget / minPrice;

        return (int)ans;
    }
};