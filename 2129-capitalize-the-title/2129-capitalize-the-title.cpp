class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string temp;
        string ans="";
        while(ss>>temp){
            for( char& ch:temp){
                ch=tolower(ch);
            }
            if(temp.size()>2){
                temp[0]=toupper(temp[0]);
            }
            ans+=temp+ " ";
        }
        ans.pop_back();
        return ans;
    }
};