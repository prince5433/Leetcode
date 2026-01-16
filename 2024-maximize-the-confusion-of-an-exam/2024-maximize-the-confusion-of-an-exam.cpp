class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int i=0,j=0;
        int cntf=0;
        int result=0;
        //f->t
        while(j<n){
            if(answerKey[j]=='F'){
                cntf++;
            }
            while(cntf>k){
                if(answerKey[i]=='F'){
                    cntf--;
                }
                 i++;
            }
       
            result=max(result,j-i+1);
                 j++;
        }
        i=0,j=0;
       int cntt=0;
         while(j<n){
            if(answerKey[j]=='T'){
                cntt++;
            }
            while(cntt>k){
                if(answerKey[i]=='T'){
                    cntt--;
                }
                 i++;
            }
            
            result=max(result,j-i+1);
            j++;
        }
        return result;
    }
};