class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str=countAndSay(n-1);
        string ans="";
        //33 222 5 1 => 23 32 15 11
        int freq=1;//min ek freq to hogi agr exist kr rha hai so logical
        char ch=str[0];//phle charcter ko ch me dalo and then travrse kenege and compare krenge eith all the characters
        for(int i=1;i<str.length();i++){
            char dh=str[i];
            if(ch==dh){//agr dono char same hai to freq badhate rho
                freq++;
            } else{
                ans+=(to_string(freq)+ch);//ans me dal do freq and char
                freq=1;
                ch=str[i];//reset freq and ch
            }
        }
        //last element nhi ja payega to uske liye freq abnd char ek bar aur ans me add krdo
        ans+=(to_string(freq)+ch);
        return ans;
    }
};