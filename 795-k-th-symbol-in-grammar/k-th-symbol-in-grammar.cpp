class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        if(k%2==0){//k even hai to flip and call lagi hai from k/2
            int prevAns=kthGrammar(n-1,k/2);
            if(prevAns==0) return 1;
            else return 0;
        } else{//agr k odd hai to same and call lagi hai from k/2+1
            int prevAns=kthGrammar(n-1,k/2+1);
            return prevAns;
        }
    }
};