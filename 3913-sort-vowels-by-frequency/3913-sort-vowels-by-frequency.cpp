class Solution {
public:

    // Since only lowercase vowels matter, simple helper check
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    string sortVowels(string s) {

        // freq  -> tells how many times each vowel appears
        // first -> tells where this vowel appeared for the first time
        // We need both because:
        // 1. higher frequency vowel should come first
        // 2. if frequencies tie, earlier appearing vowel should come first
        map<char,int> freq;
        map<char,int> first;

        // -------- Collect all useful information from original string --------
        for(int i=0;i<s.size();i++){

            if(isVowel(s[i])){

                // count occurrence of this vowel
                freq[s[i]]++;

                // store first position only once
                if(first.find(s[i])==first.end()){
                    first[s[i]]=i;
                }
            }
        }

        // Only these 5 vowel types can ever exist,
        // so instead of sorting all extracted vowels,
        // we just sort these 5 characters by custom rule.
        vector<char> all = {'a','e','i','o','u'};

        sort(all.begin(),all.end(),[&](char a,char b){

            // Intuition:
            // if one vowel occurs more times, it deserves to come earlier
            if(freq[a]!=freq[b]) return freq[a]>freq[b];

            // if both occur same number of times,
            // whichever appeared earlier in original string stays earlier
            return first[a]<first[b];
        });

        // temp will store the final desired vowel ordering
        // Example: aaaaoooiie
        string temp="";

        // According to sorted vowel priority,
        // append each vowel exactly freq times
        for(char ch:all){
            while(freq[ch]--){
                temp+=ch;
            }
        }

        int j=0;

        // Now rebuild the original string:
        // consonants stay fixed,
        // only vowel positions get replaced by ordered vowels from temp
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=temp[j++];
            }
        }

        return s;
    }
};