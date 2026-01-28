class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // INF ek bada number hai jo "initially unreachable" ko represent karega
        const int INF = 1e9;

        // dist[i][j] = minimum distance from city i to city j
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Har city ka distance khud se 0 hota hai
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;

        // Graph ke edges ko distance matrix me daal rahe hain
        // Undirected graph hai, isliye dono taraf update
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall Algorithm
        // k = intermediate node
        // i = source
        // j = destination
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    // Agar i -> k -> j ka path chhota hai
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // ans = final city
        // minCount = minimum reachable cities ka count
        int ans = -1, minCount = INF;

        // Har city ke liye check karenge
        for(int i = 0; i < n; i++){
            int cnt = 0;

            // Kitni cities distanceThreshold ke andar reachable hain
            for(int j = 0; j < n; j++){
                // Khud ko count nahi karna
                if(i != j && dist[i][j] <= distanceThreshold)
                    cnt++;
            }

            // Agar count chhota hai ya equal hai
            // equal hone par bada index lena hai
            if(cnt <= minCount){
                minCount = cnt;
                ans = i;
            }
        }

        // Required city return
        return ans;
    }
};
