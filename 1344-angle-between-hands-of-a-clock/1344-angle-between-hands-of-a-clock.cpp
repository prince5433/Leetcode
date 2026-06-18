class Solution {
public:
    double angleClock(int hour, int minutes) {

        /*
        Intuition:

        Find:
        1) Minute hand angle
        2) Hour hand angle

        Then calculate difference.

        Smaller angle required:
        min(diff, 360-diff)
        */

        /*
        Minute hand:

        60 min -> 360°

        1 min -> 6°

        Angle =
        minutes * 6
        */
        double min_angle = minutes * 6;

        /*
        Hour hand:

        12 hours -> 360°

        1 hour -> 30°

        But hour hand also moves
        continuously with minutes.

        Extra movement:
        0.5° per minute

        Formula:

        (hour % 12) * 30
        +
        minutes * 0.5
        */
        double hour_angle = (hour % 12) * 30 + minutes * 0.5;

        // Absolute difference
        double diff = abs(min_angle - hour_angle);

        /*
        Two possible angles:

        diff
        or
        360 - diff

        Return smaller one.
        */
        return min(diff, 360 - diff);
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

hour = 3
minutes = 30

--------------------------------

Minute Hand:

30 * 6

= 180°

--------------------------------

Hour Hand:

3 * 30

= 90°

Plus:

30 * 0.5

= 15°

Total:

105°

--------------------------------

Difference:

|180 - 105|

= 75°

Other angle:

360 - 75

= 285°

Answer:

75°

------------------------------------------------

Important Formula

Minute Hand:
minutes * 6

Hour Hand:
(hour % 12) * 30
+
minutes * 0.5

------------------------------------------------

TC:

O(1)

------------------------------------------------

SC:

O(1)

------------------------------------------------

Pattern:

Math
Geometry
Clock Angles
*/