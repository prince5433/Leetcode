class MyHashSet {
public:
    vector<bool> ans;   // Direct access array: index = key, value = present/absent

    MyHashSet() {
        // Constraints ke according key 0 se 10^6 tak ho sakti hai
        // Isliye size 10^6 + 1 ka vector bana rahe hain
        ans.resize(1000001, false);
    }
    
    void add(int key) {
        // Key ko set me add kar rahe hain
        // true ka matlab key present hai
        ans[key] = true;
    }
    
    void remove(int key) {
        // Key ko set se remove kar rahe hain
        // false ka matlab key ab present nahi hai
        ans[key] = false;
    }
    
    bool contains(int key) {
        // Check kar rahe hain ki key set me hai ya nahi
        return ans[key];
    }
};
