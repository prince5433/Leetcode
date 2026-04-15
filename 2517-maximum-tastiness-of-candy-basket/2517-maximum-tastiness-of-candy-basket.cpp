/*
==================== 🧠 INTUITION ====================

Hume k candies choose karni hain aise ki:
👉 unke beech ka MINIMUM difference maximum ho

Example:
Agar hum candies pick karte hain → [a, b, c]
Toh tastiness = min(|a-b|, |a-c|, |b-c|)

Aur hume iss value ko MAXIMIZE karna hai

-----------------------------------------------------

👉 Yeh "MAXIMIZE MINIMUM" type problem hai

Iska standard approach:
✔ Binary Search on Answer

-----------------------------------------------------

WHY BINARY SEARCH?

Socho hum guess karte hain:
"Answer = x"

Aur check karte hain:
👉 Kya hum k candies pick kar sakte hain jinka minimum difference ≥ x ho?

Observations:
- Agar x possible hai → smaller values bhi possible hongi
- Agar x possible nahi hai → bade values bhi possible nahi honge

👉 Yeh monotonic behavior hai → Binary Search apply kar sakte hain

-----------------------------------------------------

GREEDY CHECK:

Given x:
- First candy hamesha pick karo
- Next candy tabhi pick karo jab:
      (current_price - last_taken_price >= x)

👉 Yeh greedy approach maximum candies pick karega

Agar count ≥ k → possible
warna → not possible

-----------------------------------------------------

FINAL APPROACH:

1. Sort array
2. Binary search on answer (minimum difference)
3. Har mid ke liye greedy check
4. Maximum valid mid return karo

Time Complexity: O(n log n)
=====================================================
*/

class Solution {
public:

    // 🔍 Check function: kya hum k candies pick kar sakte hain with min diff ≥ mid
    bool check(int mid, vector<int>& price, int k) {

        int cnt = 1;                 // first candy hamesha pick karenge
        int last = price[0];         // last picked candy

        // remaining candies check karo
        for (int i = 1; i < price.size(); i++) {

            // agar current candy ka difference ≥ mid hai
            if (price[i] - last >= mid) {
                cnt++;              // is candy ko pick kar lo
                last = price[i];    // update last picked
            }
        }

        // agar k candies mil gayi → valid hai
        return cnt >= k;
    }


    int maximumTastiness(vector<int>& price, int k) {

        // Step 1: sort karna zaroori hai
        sort(price.begin(), price.end());

        int lo = 0;                                      // minimum possible tastiness
        int hi = price.back() - price[0];                // maximum possible tastiness
        int ans = 0;

        // 🔎 Binary Search on answer
        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;                // current guess

            if (check(mid, price, k)) {
                ans = mid;                              // valid answer
                lo = mid + 1;                           // try bigger value
            } 
            else {
                hi = mid - 1;                           // try smaller value
            }
        }

        return ans;
    }
};