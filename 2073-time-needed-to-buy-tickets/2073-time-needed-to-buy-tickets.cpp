class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<pair<int,int>> qu;  
        // queue stores {remaining_tickets, person_index}

        int n = tickets.size();

        // Push all people into queue
        for(int i = 0; i < n; i++){
            qu.push({tickets[i], i});
        }

        int time = 0;

        // Simulate real queue
        while(!qu.empty()){

            // Take the front person
            int tkt = qu.front().first;   // how many tickets they need
            int idx = qu.front().second;  // their index in original array
            qu.pop();                     // remove them from the queue

            tkt--;     // they buy 1 ticket
            time++;    // 1 second passed

            // If this is person k and he bought his last ticket → done
            if(idx == k && tkt == 0){
                return time;
            }

            // If still needs tickets, send them to the back of the queue
            if(tkt > 0){
                qu.push({tkt, idx});
            }
        }

        return time;
    }
};
