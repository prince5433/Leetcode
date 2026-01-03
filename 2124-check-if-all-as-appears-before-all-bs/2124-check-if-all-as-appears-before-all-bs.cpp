class Solution {
public:
    bool checkString(string s) {

        // agar string ke andar "ba" substring mil gaya
        // matlab 'b' ke baad 'a' aa raha hai → invalid
        if (s.find("ba") != string::npos)
            return false;

        // warna saare 'a' pehle aur 'b' baad me hain → valid
        return true;
    }
};
