class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        vector<int> t1,t2;
        for(string str:event1){
            string hour=str.substr(0,2);
            string min=str.substr(3);
            int hr=stoi(hour);
            int mi=stoi(min);
            int time=60*hr+mi;
            t1.push_back(time);
        }
          for(string str:event2){
            string hour=str.substr(0,2);
            string min=str.substr(3);
            int hr=stoi(hour);
            int mi=stoi(min);
            int time=60*hr+mi;
            t2.push_back(time);
        }
   if((t2[0]>=t1[0] && t2[0]<=t1[1])||(t1[0]>=t2[0] && t1[0]<=t2[1])) return true;
        else return false;
    }
};