class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allUpper=true;
        bool allLower=true;
        bool firstUprestLower=true;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(!isupper(ch)) allUpper=false;
            if(!islower(ch)) allLower=false;
            if(i==0){
                if(!isupper(ch)) firstUprestLower=false;
            } else{
                if(!islower(ch)) firstUprestLower=false;
            }
        }
        return allUpper || allLower || firstUprestLower;
    }
};