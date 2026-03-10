class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {

        // volume calculate kar rahe hain (long long use kiya overflow avoid karne ke liye)
        long long volume = 1LL * length * width * height;

        // initially assume box bulky aur heavy nahi hai
        bool bulky = false;
        bool heavy = false;

        // agar mass >= 100 hai to box heavy hai
        if(mass >= 100){
            heavy = true;
        }

        // bulky hone ke conditions:
        // 1. volume >= 10^9
        // 2. ya koi dimension >= 10^4
        if(volume >= 1000000000 || length >= 10000 || width >= 10000 || height >= 10000){
            bulky = true;
        }

        // agar bulky bhi hai aur heavy bhi
        if(bulky && heavy){
            return "Both";
        }

        // agar dono false hain
        else if(!bulky && !heavy){
            return "Neither";
        }

        // agar bulky hai but heavy nahi
        else if(bulky && !heavy){
            return "Bulky";
        }

        // agar heavy hai but bulky nahi
        else{
            return "Heavy";
        }
    }
};