class Solution {
public:
    int sumBase(int n, int k) {
        string basek="";
        while(n>0){
            basek+=to_string(n%k);
            n/=k;
        }
        int baseke=stoi(basek);
        int sum=0;
        while(baseke>0){
            sum+=baseke%10;
            baseke/=10;
        }
        return sum;
    }
};