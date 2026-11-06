
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // m = total number of log entries
        int m = logs.size();

        // STEP 1: SORT LOGS BY TIMESTAMP
        //
        // logs[i][0] = server ID
        // logs[i][1] = timestamp
        //
        // We sort logs according to timestamp so that
        // our sliding window can move only in forward direction.
        //
        // WHY?
        // Queries will also be processed in increasing order.
        // Therefore, we never need to move our log pointers backward.
        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        // STEP 2: STORE QUERIES WITH THEIR ORIGINAL INDEX
        //
        // pair = {query_time, original_index}
        //
        // WHY STORE ORIGINAL INDEX?
        // We need to sort queries by time to process them efficiently.
        // But the final answer must be in the original query order.
        //
        // Example:
        // queries = {10, 5}
        //
        // queri = {{10, 0}, {5, 1}}
        // After sorting:
        // queri = {{5, 1}, {10, 0}}
        //
        // We use the original index to put answers in correct positions.

        vector<pair<int,int>> queri;

        for(int i = 0; i < queries.size(); i++) {
            queri.push_back({queries[i], i});
        }

        // Process queries from smallest time to largest time.
        sort(queri.begin(), queri.end());

        // STEP 3: ANSWER ARRAY
        //
        // ans[i] stores the answer for queries[i].
        // Initially, all answers are zero.
        vector<int> ans(queries.size(), 0);

        // STEP 4: FREQUENCY MAP
        //
        // mp[server_id] = number of logs of that server
        // currently present inside our sliding window.
        //
        // WHY FREQUENCY MAP?
        // A server may generate multiple logs.
        // Even if one log goes outside the window,
        // the server must remain active if another log
        // is still inside the window.
        //
        // Example:
        // mp[1] = 2 means server 1 has two active logs.
        // When one log expires, frequency becomes 1.
        // Server 1 is still active.

        unordered_map<int,int> mp;

        // STEP 5: TWO POINTERS
        //
        // i = index of the first log currently inside the window.
        // j = index of the first log not yet added to the window.
        //
        // Current active log range = [i, j-1]
        //
        // Both pointers move only forward because logs
        // and queries are sorted.

        int i = 0;
        int j = 0;

        // STEP 6: PROCESS SORTED QUERIES
        for(auto& q : queri) {

            // Current query time
            int time = q.first;

            // Original position of this query
            int idx = q.second;

            // Required time interval:
            // [time - x, time]
            //
            // Both boundaries are inclusive.
            int s = time - x;
            int e = time;

            // STEP 7: EXPAND THE WINDOW FROM RIGHT
            //
            // Add every log whose timestamp <= e.
            //
            // WHY?
            // These logs have reached the right boundary
            // of our current query window.
            //
            // We add their server IDs to the frequency map.
            //
            // j moves forward so that no log is added twice.

            while(j < m && logs[j][1] <= e) {

                // This server has one more log inside
                // the current candidate window.
                mp[logs[j][0]]++;

                j++;
            }

            // STEP 8: SHRINK THE WINDOW FROM LEFT
            //
            // Remove logs whose timestamp < s.
            //
            // WHY STRICTLY LESS THAN?
            // The interval is [s, e].
            // Therefore, a log exactly at timestamp s
            // must remain inside the window.
            //
            // i < j ensures that we remove only logs
            // which have already been added.

            while(i < j && logs[i][1] < s) {

                // Identify the server whose old log is expiring.
                int server = logs[i][0];

                // One log of this server is leaving the window.
                mp[server]--;

                // If frequency becomes zero, this server
                // has no logs remaining in the current window.
                //
                // Therefore, it is no longer an active server.
                if(mp[server] == 0) {
                    mp.erase(server);
                }

                i++;
            }

            // STEP 9: CALCULATE INACTIVE SERVERS
            //
            // mp.size() = number of DISTINCT active servers.
            //
            // Total servers = n
            //
            // Inactive servers =
            // Total servers - Active servers
            //
            // Store the answer at the original query index,
            // not at the sorted query position.

            ans[idx] = n - mp.size();
        }

        // Return answers in the original queries order.
        return ans;
    }
};

// TIME COMPLEXITY:
// O(m log m + q log q)
// m = number of logs
// q = number of queries
//
// Sorting logs: O(m log m)
// Sorting queries: O(q log q)
// Sliding window: O(m + q) average
// Every log is added once and removed at most once.
//
// SPACE COMPLEXITY:
// O(m + q)
// Logs are sorted in-place.
// Query pairs require O(q).
// HashMap requires O(n) maximum space.
// Sorting may additionally use O(log m + log q) stack space.
