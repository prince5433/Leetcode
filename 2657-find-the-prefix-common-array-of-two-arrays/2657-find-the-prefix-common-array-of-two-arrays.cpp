class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=B.size();
        vector<int> C(n,0);
        int count=0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(st.find(A[i])!=st.end()) count++;
            else st.insert(A[i]);

            if(st.find(B[i])!=st.end()) count++;
            else st.insert(B[i]);

            C[i]=count;
        }
        return C;
    }
};