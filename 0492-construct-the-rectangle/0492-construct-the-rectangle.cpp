class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans;                    // answer store karega [L, W]

        int finde = sqrt(area);             // sqrt(area) se start karenge (closest factors milte hain)

        for(int i = finde; i >= 1; i--){    // i ko sqrt se 1 tak check kar rahe
            int d1 = i;                     // possible width
            int d2 = area / i;              // corresponding length

            // agar d1 factor hai to d1*d2 exactly area hoga
            if(d1 * d2 == area){
                ans.push_back(d1);          // factor 1 push
                ans.push_back(d2);          // factor 2 push
                break;                      // first valid pair best hota hai (min difference)
            }
        }

        sort(ans.rbegin(), ans.rend());     // descending sort so ans[0] = L (bigger), ans[1] = W (smaller)
        return ans;                         // return [L, W]
    }
};
