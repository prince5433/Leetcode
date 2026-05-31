class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();
   
    long long curr=mass;
    for(int ast:asteroids){
        if(curr<ast){
            return false;
        }
        curr+=ast;
    }
    return true;
     }
};