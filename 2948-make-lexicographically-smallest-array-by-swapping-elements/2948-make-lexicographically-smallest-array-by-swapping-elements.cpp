class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        // {value, original_index}
        //
        // WHY index bhi store karna hai?
        // Kyuki sorting ke baad hume pata hona chahiye
        // ki original array me ye value kis position par thi.
        vector<pair<int, int>> indexed;

        for (int i = 0; i < nums.size(); i++) {
            indexed.push_back({nums[i], i});
        }

        // WHY sort?
        //
        // Hume values ke basis par check karna hai
        // ki kaunse elements ek group me aa sakte hain.
        //
        // Sorting ke baad agar adjacent values ka difference
        // <= limit hai, to ye dono ek dusre se connected hain.
        sort(indexed.begin(), indexed.end());


        // First element se first group start karo.
        //
        // indexed[0].second = us value ka original index.
        vector<vector<int>> groups = {
            {indexed[0].second}
        };


        // Sorted values ko traverse karo.
        for (int i = 1; i < nums.size(); i++) {

            // WHY adjacent difference check?
            //
            // Agar:
            //
            // current value - previous value <= limit
            //
            // to in dono values ko swap/rearrange karna possible hai.
            //
            // Aur agar chain ban jaye:
            //
            // 1 -> 3 -> 5
            //
            // limit = 2
            //
            // 1 and 3 connected
            // 3 and 5 connected
            //
            // To indirectly 1, 3, 5 ek hi group me aa jayenge.
            if (indexed[i].first - indexed[i - 1].first <= limit) {

                // Current index ko existing group me add karo.
                groups.back().push_back(indexed[i].second);

            } else {

                // Difference limit se greater hai,
                // iska matlab previous group aur current value
                // ke beech koi connection nahi hai.
                //
                // Isliye new group start karo.
                groups.push_back({
                    indexed[i].second
                });
            }
        }


        // Ab har group ke andar values ko
        // smallest possible order me arrange karenge.
        for (auto& group : groups) {

            // Is group ke saare actual values nikalo.
            vector<int> sortedVals;

            for (int i : group) {
                sortedVals.push_back(nums[i]);
            }

            // WHY sort values?
            //
            // Hume lexicographically smallest array chahiye.
            // Isliye group ki smallest value ko
            // smallest available index par rakhna hai.
            sort(sortedVals.begin(), sortedVals.end());


            // WHY sort indices?
            //
            // Group ke original indices ko ascending order me rakhenge.
            //
            // Example:
            //
            // indices = [5, 1, 3]
            //
            // Sort ->
            //
            // [1, 3, 5]
            //
            // Ab smallest value index 1 par,
            // next smallest index 3 par,
            // etc. jayegi.
            sort(group.begin(), group.end());


            // Sorted values ko sorted indices par assign karo.
            //
            // Example:
            //
            // indices = [1, 3, 5]
            // values  = [2, 4, 7]
            //
            // Result:
            //
            // nums[1] = 2
            // nums[3] = 4
            // nums[5] = 7
            for (int i = 0; i < group.size(); i++) {
                nums[group[i]] = sortedVals[i];
            }
        }

        return nums;
    }
};

/*
---------------- INTUITION ----------------

Hume array ko lexicographically smallest banana hai.

Lekin swap tabhi possible hai jab
do elements ka absolute difference <= limit ho.

Suppose:

nums = [5, 1, 3]
limit = 2

Sorted values:

1, 3, 5

1 and 3 ka difference = 2
3 and 5 ka difference = 2

To:

1 -> 3 -> 5

Ek chain ban gayi.

Isliye ye teeno ek hi group me hain
aur inke original positions ke beech
values freely rearrange ki ja sakti hain.

---------------- GROUPING ----------------

Sorted values:

1  3  5  10  11

limit = 2

Check:

3 - 1 = 2  -> same group
5 - 3 = 2  -> same group
10 - 5 = 5 -> new group
11 - 10 = 1 -> same group

Groups:

[1, 3, 5]

[10, 11]

Har group ke andar hum
values ko smallest possible order me
original indices par place kar sakte hain.

---------------- WHY SORT INDICES ----------------

Suppose group ke original indices:

[4, 1, 3]

Agar smallest value ko
index 4 par rakh diya,
to array lexicographically smallest nahi banega.

Isliye indices ko sort karte hain:

[1, 3, 4]

Aur values ko bhi sort karte hain:

[2, 5, 8]

Then:

index 1 -> 2
index 3 -> 5
index 4 -> 8

Isse group ka contribution
lexicographically smallest ho jata hai.

---------------- TIME COMPLEXITY ----------------

Indexed pairs ko sort:

O(n log n)

Groups ke andar values sort:

Overall O(n log n)

Groups ke indices sort:

Overall O(n log n)

Therefore:

TC = O(n log n)

---------------- SPACE COMPLEXITY ----------------

Indexed array:

O(n)

Groups:

O(n)

Sorted values:

O(n)

Overall:

SC = O(n)

---------------- PATTERN ----------------

Sorting

+

Greedy

+

Connected Groups

+

Lexicographical Optimization
*/