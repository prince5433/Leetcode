class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {

        vector<int> t1, t2;

        // convert event1 times into minutes
        for(string str : event1){
            string hour = str.substr(0,2);
            string min = str.substr(3);

            int hr = stoi(hour);
            int mi = stoi(min);

            int time = 60*hr + mi;
            t1.push_back(time);
        }

        // convert event2 times into minutes
        for(string str : event2){
            string hour = str.substr(0,2);
            string min = str.substr(3);

            int hr = stoi(hour);
            int mi = stoi(min);

            int time = 60*hr + mi;
            t2.push_back(time);
        }

        // check if event2 start lies inside event1
        // OR event1 start lies inside event2
        if((t2[0] >= t1[0] && t2[0] <= t1[1]) || 
           (t1[0] >= t2[0] && t1[0] <= t2[1])) 
            return true;

        return false;
    }
};