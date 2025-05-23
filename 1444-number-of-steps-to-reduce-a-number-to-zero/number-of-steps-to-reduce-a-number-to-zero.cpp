class Solution {
public:

    int numberOfSteps(int num) {
        //static int count=0;
        if(num==0) return 0;
        if(num%2==0){
            return 1+ numberOfSteps(num/2);
        }
        else{
            return 1+ numberOfSteps(num-1);      
        }
        return 0;
        
    }
};