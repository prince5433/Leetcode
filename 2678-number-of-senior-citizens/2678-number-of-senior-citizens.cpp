class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(string str:details){
            int age=stoi(str.substr(11,2));
            if(age>60) cnt++;
        }
        return cnt;
    }
};