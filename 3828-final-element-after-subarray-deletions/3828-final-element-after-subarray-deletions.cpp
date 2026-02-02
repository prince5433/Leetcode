class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size(); 
        // array ka current length

        if (n == 1) 
            // agar array me sirf ek element hai,
            // game start hi nahi hota, wahi answer hai
            return nums[0];

        // 🔑 GAME LOGIC:
        // Har turn me player ek proper subarray (poora array nahi) remove karta hai
        // Iska matlab final me jo element bachega
        // wo ya to left end ka hoga ya right end ka
        //
        // Alice (first player) final element ko maximize karna chahti hai
        // Bob (second player) final element ko minimize karna chahta hai
        //
        // Optimal play me:
        // - Alice kabhi bhi beech ka element forcefully final tak nahi laa sakti
        // - Endpoints hi candidates bante hain
        //
        // Isliye answer = max(first element, last element)
        return max(nums[0], nums[n - 1]);
    }
};
