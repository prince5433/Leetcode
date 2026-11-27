class Solution {
public:
vector<vector<int>> dist;
vector<vector<int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        dist.assign(n, vector<int>(m, -1));
        queue<pair<int,int>> q;
         q.push({entrance[0], entrance[1]});
        dist[entrance[0]][entrance[1]]=0;
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();

            if((r==0 || c==0|| r==n-1 ||c==m-1 ) && !(r==entrance[0] && c==entrance[1])){
                return dist[r][c];
            }
            for(auto d:dirs){
                int nr=r+d[0];
                int nc=c+d[1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && dist[nr][nc]==-1 && maze[nr][nc]=='.'){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return -1;
    }
};