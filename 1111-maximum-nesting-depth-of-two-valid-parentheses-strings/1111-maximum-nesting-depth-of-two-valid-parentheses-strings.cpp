class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res;
        int depth = 0;

        for (char c : seq) {
            if (c == '(') {
                // Opening bracket ko current depth ke parity ke basis par group do.
                // Uske baad depth badhao, kyunki ab hum ek level andar aa gaye.
                res.push_back(depth % 2);
                depth++;
            } else {
                // Closing bracket par pehle depth kam karo,
                // kyunki bracket close hone ke baad hum ek level bahar aate hain.
                depth--;

                // Closing bracket ko updated depth ke parity wale group mein rakho.
                res.push_back(depth % 2);
            }
        }

        return res;
    }
};