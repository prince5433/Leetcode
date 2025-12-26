class Solution {
public:
    int bestClosingTime(string customers) {

        int penalty = 0;

        // Step 1: Assume shop is closed the whole day
        // Penalty will be number of 'Y' (customers come but shop is closed)
        for(char c : customers) {
            if(c == 'Y') penalty++;
        }

        // Store minimum penalty found so far
        int minPenalty = penalty;

        // Best time to close shop (initially 0 = closed all day)
        int bestTime = 0;

        // Step 2: Move closing time from left to right
        for(int i = 0; i < customers.size(); i++) {

            // If customer comes ('Y') and we keep shop open
            // then we remove 1 penalty
            if(customers[i] == 'Y')
                penalty--;

            // If no customer ('N') and shop is open
            // then we add 1 penalty
            else
                penalty++;

            // Check if current penalty is minimum
            if(penalty < minPenalty) {
                minPenalty = penalty;   // update minimum penalty
                bestTime = i + 1;       // closing time is next hour
            }
        }

        // Return the best closing time
        return bestTime;
    }
};
