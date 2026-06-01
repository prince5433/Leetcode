class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {

        /*
        Intuition:

        Kisi index i ko remove karne ke baad,
        uske right wale saare elements
        ek position left shift ho jaate hain.

        Isliye unki parity flip ho jaati hai:

        Even -> Odd
        Odd  -> Even

        Hum left aur right side ke
        even/odd sums maintain karenge.
        */

        int rightEven = 0, rightOdd = 0;
        int leftEven = 0, leftOdd = 0;

        /*
        Initially saare elements
        right side me assume karo.
        */
        for (int i = 0; i < nums.size(); i++) {

            if (i % 2 == 0) {
                rightEven += nums[i];
            } else {
                rightOdd += nums[i];
            }
        }

        int count = 0;

        // Try removing every index
        for (int i = 0; i < nums.size(); i++) {

            /*
            Current element remove kar rahe.
            Isliye right side se hata do.
            */
            if (i % 2 == 0) {
                rightEven -= nums[i];
            } else {
                rightOdd -= nums[i];
            }

            /*
            Removal ke baad:

            Left side parity same rahegi.

            Right side parity flip hogi.

            New Even:
            leftEven + rightOdd

            New Odd:
            leftOdd + rightEven
            */
            int newEvenSum = leftEven + rightOdd;
            int newOddSum  = leftOdd + rightEven;

            // Fair array ban gaya
            if (newEvenSum == newOddSum) {
                count++;
            }

            /*
            Next iteration ke liye
            current element left side me add karo.
            */
            if (i % 2 == 0) {
                leftEven += nums[i];
            } else {
                leftOdd += nums[i];
            }
        }

        return count;
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

nums = [2,1,6,4]

Remove index 1:

New array:
[2,6,4]

Even positions:
2 + 4 = 6

Odd positions:
6

Fair => valid

------------------------------------------------

Main Trick:

Index remove hone ke baad
right side ke elements shift hote hain.

Parity change:

Even -> Odd
Odd -> Even

Isi liye:

newEven = leftEven + rightOdd
newOdd  = leftOdd + rightEven

------------------------------------------------

TC:

First loop  -> O(n)
Second loop -> O(n)

Total:
O(n)

------------------------------------------------

SC:

Only variables used.

O(1)

------------------------------------------------

Pattern:

Prefix Sum
Parity Observation
Array Simulation
*/