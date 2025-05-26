class Solution {
public:
       //hame sirf last ke 3 variables k kam hai to pure array ko store kyo kre isse accha sirf teen varaibale maintain kr skte h
       int f(int n){
        //base cases handle krna padga hen n<3 to d bnega hi nahi
     if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;


    int a=0;
    int b=1;
    int c=1;
    int i=3;
    int d;
    while(i<=n){
        d=c+a+b;
        a=b;
        b=c;
        c=d;
        i++;
    }
    return d;
    }
    int tribonacci(int n) {
        return f(n);
    }
};