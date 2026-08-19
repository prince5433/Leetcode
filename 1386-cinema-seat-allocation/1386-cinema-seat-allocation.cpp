class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // mp[row] me us row ki saari reserved seats store hongi.
        //
        // WHY unordered_map?
        // Sirf wahi rows important hain jahan koi seat reserved hai.
        // Baaki rows completely empty hain aur unme directly 2 families
        // baith sakti hain.
        unordered_map<int, unordered_set<int>> mp;

        for (auto& reservedSeat : reservedSeats) {

            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            // Current row ki reserved seat store karo.
            mp[row].insert(seat);
        }

        // Jin rows me ek bhi reserved seat nahi hai,
        // unme maximum 2 families easily baith sakti hain.
        //
        // WHY 2?
        // Ek family ko 4 consecutive seats chahiye:
        //
        // 2 3 4 5
        // 6 7 8 9
        //
        // Total 10 seats me 2 families possible hain.
        int result = (n - mp.size()) * 2;

        // Sirf reserved wali rows process karo.
        for (auto& [row, bookedSeats] : mp) {

            // Check karega ki given seat reserved nahi hai.
            //
            // WHY lambda?
            // Same checking logic baar-baar use karna hai,
            // isliye ek small helper bana diya.
            auto isAvailable = [&](int seat) {
                return bookedSeats.find(seat) == bookedSeats.end();
            };

            // Group A:
            //
            // Seats 2,3,4,5
            bool groupA =
                isAvailable(2) &&
                isAvailable(3) &&
                isAvailable(4) &&
                isAvailable(5);

            // Group B:
            //
            // Seats 4,5,6,7
            bool groupB =
                isAvailable(4) &&
                isAvailable(5) &&
                isAvailable(6) &&
                isAvailable(7);

            // Group C:
            //
            // Seats 6,7,8,9
            bool groupC =
                isAvailable(6) &&
                isAvailable(7) &&
                isAvailable(8) &&
                isAvailable(9);

            // WHY groupA && groupC?
            //
            // Agar A aur C dono available hain,
            // to 2 families baith sakti hain:
            //
            // Family 1 -> 2,3,4,5
            // Family 2 -> 6,7,8,9
            //
            // In dono groups me koi overlap nahi hai.
            if (groupA && groupC) {

                result += 2;
            }

            // Agar A aur C dono available nahi hain,
            // lekin inme se koi ek available hai,
            // to sirf 1 family baith sakti hai.
            //
            // Group B bhi ek family ke liye enough hai.
            else if (groupA || groupB || groupC) {

                result += 1;
            }

            // Agar koi bhi group available nahi hai,
            // to current row se 0 families add hongi.
        }

        return result;
    }
};

/*
---------------- INTUITION ----------------

Har row me total 10 seats hain:

1 2 3 4 5 6 7 8 9 10

Family ko exactly 4 consecutive seats chahiye.

Possible groups:

Group A:
2 3 4 5

Group B:
4 5 6 7

Group C:
6 7 8 9

---------------- IMPORTANT ----------------

A aur C ek saath use ho sakte hain:

A = 2 3 4 5
C = 6 7 8 9

Isliye maximum 2 families.

Lekin B kisi ke saath
2-family combination nahi bana sakta,
kyunki B:

4 5 6 7

A aur C dono ke saath overlap karta hai.

Isliye:

A && C -> 2 families

A || B || C -> 1 family

None -> 0 families

---------------- WHY EMPTY ROWS SEPARATELY ----------------

Agar kisi row me koi reserved seat hi nahi hai,

to:

2 3 4 5
+
6 7 8 9

dono groups completely free honge.

Isliye har completely empty row
directly 2 families contribute karegi.

(n - number of rows having reservations) * 2

---------------- SMALL BUG IN YOUR CODE ----------------

Tumhare original code me:

isAvailable(4) & isAvailable(5)

single '&' use hua tha.

Correct:

isAvailable(4) && isAvailable(5)

'&' = bitwise AND

'&&' = logical AND

Boolean conditions ke liye hume
'&&' use karna chahiye.

---------------- Time Complexity ----------------

Let:

R = Number of rows having reservations
E = Number of reserved seats

HashMap build:

O(E) average

Har affected row me sirf
constant number of seats check ho rahi hain.

O(R)

Overall:

TC = O(E + R)

Since R <= E:

TC = O(E) average

---------------- Space Complexity ----------------

HashMap me reserved seats store hain.

SC = O(E)
*/