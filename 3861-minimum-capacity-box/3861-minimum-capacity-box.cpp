class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {

        int n = capacity.size();

        // pair: {capacity, original index}
        vector<pair<int,int>> v;

        // capacities ko index ke saath store kar rahe hain
        for(int i = 0; i < n; i++){
            v.push_back({capacity[i], i});
        }

        // capacity ke basis par sort karte hain
        sort(v.begin(), v.end());

        // smallest capacity se check karte hain
        for(int i = 0; i < n; i++){

            // agar capacity itemSize se >= hai
            if(v[i].first >= itemSize){

                // original index return karo
                return v[i].second;
            }
        }

        // agar koi capacity sufficient nahi mili
        return -1;
    }
};