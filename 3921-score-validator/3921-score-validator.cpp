class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {

        // score -> stores total runs
        // cnt -> stores number of wickets
        int score = 0, cnt = 0;

        int n = events.size();
        int i = 0;

        // Process events until:
        // 1. all events are processed
        // 2. wickets become 10
        while (i < n && cnt < 10) {

            // If wicket falls
            // increase wicket counter only
            if (events[i] == "W") {
                cnt++;
            }

            // Wide ball or No ball
            // add 1 extra run
            else if (events[i] == "WD" || events[i] == "NB") {
                score += 1;
            }

            // Otherwise event contains runs like
            // "0","1","2","3","4","6"
            else {
                score += stoi(events[i]);
            }

            i++;
        }

        // return final score and wickets
        return {score, cnt};
    }
};