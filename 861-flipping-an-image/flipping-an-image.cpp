class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>>ans;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=m-1;j>=0;j--){
                temp.push_back(1-image[i][j]);//flip aur invert dono ek sath
            }
            ans.push_back(temp);
           
        }
        return ans;
    }
};