class Solution {
public:
bool isVowel(char ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}
    string sortVowels(string s) {
        map<char,int> freq;
        map<char,int> first;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){

                freq[s[i]]++;
                if(first.find(s[i])==first.end()){
                    first[s[i]]=i;
                }
            }
        }
        vector<char>all={'a','e','i','o','u'};
        sort(all.begin(),all.end(),[&](char a,char b){
            if(freq[a]!=freq[b]) return freq[a]>freq[b];
            return first[a]<first[b];
        });
        string temp="";
        for(char ch:all){
            while(freq[ch]--){
                temp+=ch;
            }
        }
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=temp[j++];
            }
        }
        return s;
    }
};