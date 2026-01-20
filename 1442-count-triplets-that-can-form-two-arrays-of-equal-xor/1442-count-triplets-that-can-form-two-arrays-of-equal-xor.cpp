class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();

        // prefix xor array of size n+1
        // prexore[0] = 0
        // prexore[i+1] = arr[0] ^ arr[1] ^ ... ^ arr[i]
        vector<int> prexore(n + 1, 0);

        // build prefix xor
        for(int i = 0; i < n; i++){
            prexore[i + 1] = prexore[i] ^ arr[i];
        }

        int trips = 0;

        // i -> start index
        // k -> end index
        for(int i = 0; i < n; i++){
            for(int k = i + 1; k < n; k++){

                // if prexore[i] == prexore[k+1]
                // then xor(i..k) = 0
                // and for this (i,k), j can be any value from i+1 to k
                // total (k - i) valid triplets
                if(prexore[i] == prexore[k + 1])
                    trips += (k - i);
            }
        }

        return trips;
    }
};
