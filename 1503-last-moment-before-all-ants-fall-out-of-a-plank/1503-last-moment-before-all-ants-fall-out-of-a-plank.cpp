class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;   
        // INTUITION:
        // Ants jab collide karti hain to direction swap hota hai,
        // jo practically same hai jaise ants ek-dusre ko ignore karke
        // seedhi chal rahi ho. Isliye collision consider karne ki zarurat nahi.

        // Left jaane wali ants:
        // Fall time = unki current position
        for (int x : left) {
            ans = max(ans, x);
        }

        // Right jaane wali ants:
        // Fall time = n - position
        for (int x : right) {
            ans = max(ans, n - x);
        }

        // Maximum fall time = last ant ka moment
        return ans;
    }
};
