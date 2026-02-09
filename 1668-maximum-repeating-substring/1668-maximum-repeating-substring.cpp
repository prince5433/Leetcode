class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;          // number of times word repeats
        string temp = word;     // start with single word

        // keep checking while repeated word exists in sequence
        while(sequence.find(temp) != string::npos){
            count++;            // repetition found
            temp += word;       // increase repetition
        }

        return count;           // return maximum repetitions
    }
};
