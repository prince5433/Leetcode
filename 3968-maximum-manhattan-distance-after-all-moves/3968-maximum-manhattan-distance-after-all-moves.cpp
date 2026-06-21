class Solution {
public:
    int maxDistance(string moves) {

        /*
        Intuition:

        Track final displacement
        from origin.

        x-axis:
        L -> -1
        R -> +1

        y-axis:
        D -> -1
        U -> +1

        '?' can be converted into
        any direction, so each '?'
        can potentially increase
        Manhattan distance by 1.
        */

        int netx = 0;
        int nety = 0;

        // Number of unknown moves
        int under = 0;

        for(char c : moves) {

            if(c == 'U')
                nety++;

            else if(c == 'L')
                netx--;

            else if(c == 'R')
                netx++;

            else if(c == 'D')
                nety--;

            else
                under++;
        }

        /*
        Current Manhattan Distance:

        |x| + |y|

        Every '?' can be chosen
        to move further away from
        the origin.

        So add all unknown moves.
        */
        int abso =
            abs(netx)
            +
            abs(nety)
            +
            under;

        return abso;
    }
};

/*
---------------- QUICK INTUITION ----------------

Manhattan Distance:

|x| + |y|

------------------------------------------------

Example:

moves = "URDL"

Final Position:

x = 0
y = 0

Distance:

0

Answer = 0

------------------------------------------------

Example:

moves = "UR?"

Known moves:

U -> y+1
R -> x+1

Position:

(1,1)

Distance:

|1| + |1| = 2

One '?' remains.

Choose:

R

Position:

(2,1)

Distance:

3

Answer = 3

------------------------------------------------

Why + under ?

Each '?' can be converted
into the direction that increases
current distance the most.

So every unknown move
contributes +1.

------------------------------------------------

TC:

Single traversal

O(n)

------------------------------------------------

SC:

Only variables used

O(1)

------------------------------------------------

Pattern:

Simulation
Manhattan Distance
Greedy Observation
*/