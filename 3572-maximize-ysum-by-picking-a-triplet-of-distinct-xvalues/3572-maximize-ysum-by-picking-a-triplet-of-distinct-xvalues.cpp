class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {

        /*
        Intuition:
        Hume 3 distinct x values choose karne hain
        such that corresponding y sum maximum ho.

        Same x ke liye sirf maximum y useful hoga.
        */

        map<int, vector<int>> mp;

        // Group all y values by x
        for(int i = 0; i < x.size(); i++) {
            mp[x[i]].push_back(y[i]);
        }

        vector<int> temp;

        // For every distinct x
        for(auto &it : mp) {

            auto& v = it.second;

            /*
            Largest y chahiye for current x
            */
            sort(v.rbegin(), v.rend());

            // store best y for this x
            temp.push_back(v[0]);
        }

        /*
        3 distinct x possible nahi
        */
        if(temp.size() < 3)
            return -1;

        // Need top 3 maximum y values
        sort(temp.rbegin(), temp.rend());

        return temp[0] + temp[1] + temp[2];
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

x = [1,1,2,2,3]
y = [5,2,8,1,7]

Group:
1 -> [5,2]
2 -> [8,1]
3 -> [7]

Best pick:
1 -> 5
2 -> 8
3 -> 7

Answer:
5 + 8 + 7 = 20

------------------------------------------------

Why this works?

Same x multiple baar aa sakta.
But hume distinct x chahiye.

So har x ke liye sirf max y store karo.

Then top 3 choose.

------------------------------------------------

TC:
Grouping -> O(n)

Sorting groups + temp:
Overall approx O(n log n)

SC:
O(n)

------------------------------------------------

Pattern:
Hashing / Mapping
Greedy Selection
Sorting
*/