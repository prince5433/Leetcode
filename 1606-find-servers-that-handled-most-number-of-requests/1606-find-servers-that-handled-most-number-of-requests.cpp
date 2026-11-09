
class Solution {
public:
    typedef pair<int,int> P;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        int n = arrival.size();

        // Stores all currently available server IDs.
        // Initially, all k servers are available.
        set<int> avaiServers;

        for(int i = 0; i < k; i++) {
            avaiServers.insert(i);
        }
        // Initialization: k insertions, each O(log k).
        // Total: O(k log k).

        // Min heap: {finishTime, serverId}
        // Server that finishes earliest will be at the top.
        priority_queue<P, vector<P>, greater<P>> busyServers;

        // countReq[i] = number of requests handled by server i.
        vector<int> countReq(k, 0);

        vector<int> result;

        for(int i = 0; i < n; i++) {

            int arrivalTime = arrival[i];

            // STEP 1: Release all servers whose requests have finished.
            // A server becomes available when finishTime <= arrivalTime.
            while(!busyServers.empty() &&
                  busyServers.top().first <= arrivalTime) {

                int serverId = busyServers.top().second;

                busyServers.pop();       // O(log k)
                avaiServers.insert(serverId); // O(log k)
            }

            // STEP 2: If no server is available, drop this request.
            if(avaiServers.empty()) {
                continue;
            }

            // Preferred server for request i.
            // Requests are assigned in circular order.
            int targetServer = i % k;

            // Find the smallest available server ID >= targetServer.
            auto it = avaiServers.lower_bound(targetServer);
            // O(log k)

            // If no such server exists, wrap around to the smallest ID.
            if(it == avaiServers.end()) {
                it = avaiServers.begin(); // O(1)
            }

            // STEP 3: Assign request to the selected server.
            int serverId = *it;

            // Remove selected server from available set.
            avaiServers.erase(it); // O(log k)

            // Server will become available at arrivalTime + load[i].
            busyServers.push({arrivalTime + load[i], serverId});
            // O(log k)

            // Increase the number of requests handled by this server.
            countReq[serverId]++;
            // O(1)
        }

        // STEP 4: Find the maximum number of requests handled by any server.
        int maxi = *max_element(countReq.begin(), countReq.end());
        // O(k)

        // STEP 5: Collect all servers having the maximum request count.
        for(int i = 0; i < k; i++) {
            if(countReq[i] == maxi) {
                result.push_back(i);
            }
        }
        // O(k)

        return result;
    }
};

/*
TIME COMPLEXITY:

1. Initialize set:
   k insertions × O(log k) = O(k log k)

2. Outer loop:
   Runs n times.

3. Inner while:
   Each request is assigned to at most one server.
   Every assignment creates one busy heap entry.
   Every busy heap entry is removed at most once.
   Therefore, total busy server removals across all iterations <= n.
   
   Each removal + insertion into set costs O(log k).
   Total = O(n log k).

4. lower_bound:
   O(log k) per request = O(n log k).

5. Assignment operations:
   Set erase + heap push = O(log k) per assigned request.
   Total = O(n log k).

6. max_element + final loop:
   O(k) + O(k) = O(k).

FINAL TC:
O(k log k + n log k + k)
= O(k log k + n log k)
= O((n + k) log k)


SPACE COMPLEXITY:

1. Available set: O(k)
2. Busy min heap: O(k)
   At most k servers can be busy simultaneously.
3. countReq: O(k)
4. result: O(k)

FINAL SC: O(k)
*/
