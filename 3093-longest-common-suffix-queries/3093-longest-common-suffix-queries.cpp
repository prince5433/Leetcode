class Solution {
public:

    // Trie node structure
    struct trieNode {

        // idx stores index of shortest word
        // passing through current suffix path
        int idx;

        // 26 lowercase character children
        trieNode* children[26];

        // Destructor to free memory recursively
        ~trieNode() {

            // delete every child node
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    // Function to create new trie node
    trieNode* getNode(int i) {

        // dynamically create node
        trieNode* temp = new trieNode();

        // initially store given word index
        temp->idx = i;

        // initialize all children as NULL
        for(int i = 0; i < 26; i++) {
            temp->children[i] = NULL;
        }

        // return created node
        return temp;
    }

    // Insert word into trie in reverse order
    void insertTrie(trieNode* pCrawl,
                    int i,
                    vector<string>& wordsContainer) {

        // current word
        string word = wordsContainer[i];

        // length of current word
        int n = word.size();

        /*
        Reverse traversal because:
        Problem is based on suffix matching.

        Example:
        "coding"

        Insert:
        g -> n -> i -> d -> o -> c

        Same suffix words share same path.
        */

        // traverse word from back
        for(int j = n-1; j >= 0; j--) {

            // current character index
            int ch_idx = word[j] - 'a';

            // if path not present
            if(pCrawl->children[ch_idx] == NULL) {

                // create new node
                pCrawl->children[ch_idx] = getNode(i);
            }

            // move to next node
            pCrawl = pCrawl->children[ch_idx];
            
            /*
            Store shortest word index for this suffix path.

            Why?
            Agar multiple words same suffix share kare,
            to smallest length word return karna hai.
            */

            if(wordsContainer[pCrawl->idx].size() > n) {

                // update smaller word index
                pCrawl->idx = i;
            }
        }
    }

    // Search best matching suffix word
    int search(trieNode* pCrawl, string &word) {

        /*
        Default answer:
        root ka shortest word.

        Agar query ka koi suffix match hi na kare,
        yehi answer return hoga.
        */
        int result_idx = pCrawl->idx;

        // query length
        int n = word.size();

        // reverse traversal for suffix matching
        for(int i = n-1; i >= 0; i--) {

            // current character index
            int ch_idx = word[i] - 'a';

            // move in trie
            pCrawl = pCrawl->children[ch_idx];

            /*
            Path break means:
            aur suffix match possible nahi.
            */

            if(pCrawl == NULL) {

                // return last matched suffix answer
                return result_idx;
            }

            /*
            Update latest matched suffix answer.

            Jitna deep jayenge,
            utna longer suffix match milega.
            */
            result_idx = pCrawl->idx;
        }

        // full query suffix matched
        return result_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        // number of container words
        int m = wordsContainer.size();

        // number of queries
        int n = wordsQuery.size();

        // final answers
        vector<int> result(n);

        /*
        Root node.

        Initially index 0 store.
        Root stores globally shortest word index.
        */
        trieNode* root = getNode(0);

        // build trie using all container words
        for(int i = 0 ; i < m; i++) {

            /*
            Maintain globally shortest word.

            Used when no suffix match exists.
            */

            if(wordsContainer[root->idx].size() >
               wordsContainer[i].size()) {

                // update smallest word index
                root->idx = i;
            }

            // insert current word into trie
            insertTrie(root, i, wordsContainer);
        }

        // process every query
        for(int i = 0; i < n; i++) {

            // find best suffix match index
            result[i] = search(root, wordsQuery[i]);
        }

        // free entire trie memory
        delete root;

        // return all answers
        return result;
    }
};

/*
---------------- QUICK INTUITION ----------------

Normal trie -> prefix matching

But question suffix matching ka hai.

Trick:
Reverse strings.

Suffix:
"ing"

Reverse:
"gni"

Ab suffix problem prefix trie ban gaya.

------------------------------------------------

Example:

wordsContainer:
["coding","ding","king"]

Reverse insertion:
coding -> gnidoc
ding   -> gnid
king   -> gnik

Common suffix "ing"
same trie path share karega.

------------------------------------------------

Why idx store kar rahe?

Question wants:
Longest matching suffix wala word.
Tie ho to shortest length word.

So har node pe shortest word index maintain.

------------------------------------------------

TC:
Insert -> O(total characters)

Search -> O(total query characters)

Overall:
O(sum of all characters)

------------------------------------------------

SC:
Trie nodes proportional to total chars.

O(total characters)

------------------------------------------------

Pattern:
Trie
Suffix Matching
String Processing
*/