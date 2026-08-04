class Solution {
public:

    vector<int> findMissingElements(vector<int>& nums) {

        // Final answer.
        //
        // Isme saare missing numbers store honge.
        vector<int> ans;

        // WHY maximum element?
        //
        // Missing numbers sirf
        // minimum aur maximum element
        // ke beech hi check karne hain.
        int mx = *max_element(nums.begin(), nums.end());

        // WHY minimum element?
        //
        // Range ka starting point
        // minimum element hoga.
        int mn = *min_element(nums.begin(), nums.end());

        // WHY unordered_set?
        //
        // Har element ko set me store kar dete hain.
        //
        // Isse kisi number ki presence
        // average O(1) time me check ho jaati hai.
        unordered_set<int> s(nums.begin(), nums.end());

        // WHY mn se mx tak loop?
        //
        // Sirf isi range ke numbers
        // missing ho sakte hain.
        //
        // Har number check karenge.
        for (int i = mn; i <= mx; i++) {

            // Agar current number
            // set me present nahi hai,
            // to ye missing hai.
            if (!s.count(i))
                ans.push_back(i);
        }

        return ans;
    }
};

/*
---------------- INTUITION ----------------

Question bolta hai ki

minimum element

aur

maximum element

ke beech jo numbers missing hain,
unhe return karo.

---------------- Example ----------------

nums =

[2,5,1,7]

Minimum

=

1

Maximum

=

7

Range

1 2 3 4 5 6 7

Present

1 2 5 7

Missing

3 4 6

Answer

[3,4,6]

---------------- WHY HashSet ----------------

Agar har number ke liye

linear search karte,

to

O(n²)

lagta.

HashSet ki wajah se

Search

average O(1)

me ho jaati hai.

---------------- WHY min to max Loop ----------------

Missing numbers sirf

minimum

aur

maximum

ke beech hi ho sakte hain.

Isliye wahi range traverse karte hain.

---------------- Time Complexity ----------------

Let,

n = nums.size()

R = (Maximum Element - Minimum Element + 1)

Finding Minimum

O(n)

Finding Maximum

O(n)

Building HashSet

O(n)

Traversing Range

O(R)

Overall TC

O(n + R)

---------------- Space Complexity ----------------

HashSet

O(n)

Answer Array

O(k)

where,

k = Number of Missing Elements

Overall SC

O(n)
*/