#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // P stores: {weight, serverIndex}
    // T stores: {finishTime, weight, serverIndex}
    typedef pair<int,int> P;
    typedef tuple<long,int,int> T;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();  // Total number of servers
        int m = tasks.size();    // Total number of tasks

        /*
            MIN HEAP 1: FREE SERVERS

            Stores {weight, index}.

            Why?
            Jab multiple servers free hon, toh hume:
            1. Minimum weight wala server choose karna hai.
            2. Agar weight same hai, toh minimum index choose karna hai.

            greater<P> pair ko lexicographical order mein compare karta hai:
            First weight, then index.

            TC of top()    = O(1)
            TC of push()   = O(log N)
            TC of pop()    = O(log N)
        */
        priority_queue<P, vector<P>, greater<P>> freeServers;


        /*
            MIN HEAP 2: BUSY SERVERS

            Stores {finishTime, weight, index}.

            Why?
            Agar saare servers busy hain, toh hume woh server chahiye
            jo sabse pehle apna current task complete karega.

            Agar finishTime same hai:
            1. Minimum weight wala server.
            2. Agar weight bhi same hai, minimum index wala server.

            greater<T> tuple ko lexicographical order mein compare karta hai.

            TC of top()    = O(1)
            TC of push()   = O(log N)
            TC of pop()    = O(log N)
        */
        priority_queue<T, vector<T>, greater<T>> busyServers;


        /*
            STEP 1: INITIALLY ALL SERVERS ARE FREE.

            Har server ko freeServers mein insert kar rahe hain.

            servers[i] = server ka weight
            i          = server ka index

            Isliye {servers[i], i} insert karenge.

            Loop runs N times.
            Each push takes O(log N).

            Total TC = O(N log N).
        */
        for(int i = 0; i < n; i++) {

            freeServers.push({servers[i], i});
            // TC: O(log N) per insertion.
        }


        // result[i] stores the server index assigned to task i.
        // We have M tasks, so result size is M.
        vector<int> result(m);


        /*
            STEP 2: PROCESS TASKS IN ARRIVAL ORDER.

            Task i arrives at time i.

            Example:
            Task 0 arrives at time 0.
            Task 1 arrives at time 1.
            Task 2 arrives at time 2.

            Outer loop runs M times.

            Har iteration mein current task ko kisi server
            par assign karna hai.
        */
        for(int i = 0; i < m; i++) {


            /*
                STEP 3: RELEASE COMPLETED SERVERS.

                busyServers ke top par woh server hota hai
                jo sabse pehle finish hoga.

                get<0>() gives finishTime.

                Agar finishTime <= i hai:
                Matlab server current task ke arrival time tak
                apna previous task complete kar chuka hai.

                Toh us server ko busy heap se remove karke
                free heap mein daal denge.

                WHY WHILE AND NOT IF?

                Ek hi time par multiple servers free ho sakte hain.
                Isliye saare completed servers ko release karna zaroori hai.

                Each iteration:
                busyServers.pop()  = O(log N)
                freeServers.push() = O(log N)

                IMPORTANT TC:
                Ye while loop ek single task ke liye multiple times
                chal sakta hai.

                Lekin complete algorithm mein total releases O(M) hain:
                Har task assignment maximum ek server ko busy karta hai,
                aur har release kisi previously assigned task ko complete
                karta hai.

                Isliye total TC of this while loop:
                O(M log N), NOT O(M * N log N).
            */
            while(!busyServers.empty() &&
                  get<0>(busyServers.top()) <= i) {

                // Extract the server that has completed its task.
                auto [finishTime, wt, idx] = busyServers.top();
                // TC: O(1) for reading top element.

                // Remove this server from the busy heap.
                busyServers.pop();
                // TC: O(log N).

                // Server is now available for a new task.
                // Free heap stores only {weight, index}.
                freeServers.push({wt, idx});
                // TC: O(log N).
            }


            /*
                STEP 4: CHECK WHETHER ANY SERVER IS FREE.

                If freeServers is empty:
                Matlab all servers are currently processing tasks.

                In that situation, current task must wait.
            */
            if(freeServers.empty()) {


                /*
                    CASE 1: ALL SERVERS ARE BUSY.

                    busyServers.top() gives the server with:
                    1. Earliest finishTime.
                    2. Minimum weight if finishTime ties.
                    3. Minimum index if both tie.

                    We select this server because it will become
                    available before all other busy servers.
                */
                auto [finishTime, wt, idx] = busyServers.top();
                // TC: O(1).


                // Remove the selected server from busy heap.
                busyServers.pop();
                // TC: O(log N).


                // Assign the current task to this server.
                result[i] = idx;


                /*
                    IMPORTANT: CALCULATING NEW FINISH TIME.

                    Current task cannot start at time i because
                    all servers are busy.

                    It will start only after this selected server
                    completes its previous task.

                    Previous task finishes at finishTime.

                    Current task takes tasks[i] units of time.

                    Therefore:

                    New finishTime = finishTime + tasks[i]

                    We do NOT use i + tasks[i] here because
                    the current task is not starting at time i.
                */
                busyServers.push({
                    finishTime + tasks[i], wt, idx
                });
                // TC: O(log N).
            }


            /*
                CASE 2: AT LEAST ONE SERVER IS FREE.

                Since freeServers is not empty, we can assign
                the task immediately at its arrival time i.

                freeServers.top() gives:
                1. Minimum weight server.
                2. Minimum index if weights tie.
            */
            else {

                // Select the best available free server.
                auto [wt, idx] = freeServers.top();
                // TC: O(1).


                // Remove selected server from free heap.
                freeServers.pop();
                // TC: O(log N).


                // Store the assigned server index for task i.
                result[i] = idx;


                /*
                    Current task starts immediately at time i.

                    Task processing time = tasks[i].

                    Therefore:
                    finishTime = i + tasks[i]

                    This server is now busy, so insert it
                    into the busy heap.
                */
                busyServers.push({
                    i + tasks[i], wt, idx
                });
                // TC: O(log N).
            }

            /*
                IMPORTANT:
                For each task, we perform only a constant number
                of heap operations outside the release while loop.

                Each heap operation takes O(log N).
            */
        }


        // Return the server index assigned to every task.
        // TC: O(1), because vector is returned using move/NRVO
        // in typical implementations; otherwise return may copy.
        return result;
    }
};


/*
=========================================================
                TIME COMPLEXITY ANALYSIS
=========================================================

Let:
N = Number of servers
M = Number of tasks

1. INITIALIZATION:

   for(int i = 0; i < n; i++)

   Loop runs N times.

   Each freeServers.push() = O(log N).

   Total = O(N log N).


2. TASK PROCESSING:

   for(int i = 0; i < m; i++)

   Outer loop runs M times.

   For each task, we perform O(1) heap operations,
   each taking O(log N).

   Total outside the while loop = O(M log N).


3. INNER WHILE LOOP:

   Each release performs:
   busyServers.pop()  = O(log N)
   freeServers.push() = O(log N)

   A server is released only after it was assigned a task.

   Across all M tasks, total server releases are O(M).

   Therefore total while-loop complexity = O(M log N).

   It is NOT O(M * N log N).


FINAL TIME COMPLEXITY:

   O(N log N) + O(M log N) + O(M log N)

   = O(N log N + M log N)

   = O((N + M) log N)


=========================================================
                SPACE COMPLEXITY ANALYSIS
=========================================================

1. freeServers:
   At most N servers across the heaps.
   O(N)

2. busyServers:
   At most N servers across the heaps.
   O(N)

   NOTE: A server exists in only ONE heap at a time.
   So combined heap space is O(N), not O(2N) asymptotically.

3. result:
   Stores M assigned server indices.
   O(M)

4. Other variables:
   O(1)

FINAL SPACE COMPLEXITY:

   O(N + M)
=========================================================
*/