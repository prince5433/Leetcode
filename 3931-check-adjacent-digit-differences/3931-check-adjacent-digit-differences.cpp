class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        vector<int> temp;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            temp.push_back(ch-'0');
        }
        for(int i=1;i<temp.size();i++){
            if (abs(temp[i]-temp[i-1])>2) return false;
        }
        return true;
    }
};