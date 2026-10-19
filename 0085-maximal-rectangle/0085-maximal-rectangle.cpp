class Solution {
public:
    vector<int> NSR(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = n;

        // right[i] mein Next Smaller to Right ka INDEX store hoga.
        // Agar right mein koi smaller height nahi mili,
        // toh n boundary index ki tarah use hoga.
        vector<int> right(n);

        // Right se left traverse karenge,
        // kyunki hume har bar ke right mein pehli smaller height chahiye.
        for(int i = n-1; i >= 0; i--) {

            if(st.empty()) {
                // Right side mein koi valid smaller element nahi hai.
                right[i] = pseudo_index;
            } else {

                // Current height se greater ya equal heights ko remove karo.
                // Ye current bar ke nearest STRICTLY smaller element nahi ban sakti.
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();

                if(st.empty())
                    right[i] = pseudo_index;
                else
                    // Stack top par nearest smaller element ka index hai.
                    right[i] = st.top();
            }

            // Current index ko push karo taaki left-side bars
            // ke liye ye possible smaller element ban sake.
            st.push(i);
        }

        return right;
    }

    vector<int> NSL(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = -1;

        // left[i] mein Next Smaller to Left ka INDEX store hoga.
        // Agar left mein smaller height nahi mili,
        // toh -1 boundary index ki tarah use hoga.
        vector<int> left(n);

        // Left se right traverse karenge.
        for(int i = 0; i < n; i++) {

            if(st.empty()) {
                // Left side mein koi valid smaller element nahi hai.
                left[i] = pseudo_index;
            } else {

                // Greater ya equal heights ko pop karo,
                // kyunki hume strictly smaller height chahiye.
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();

                if(st.empty())
                    left[i] = pseudo_index;
                else
                    // Stack top par nearest smaller element ka index hai.
                    left[i] = st.top();
            }

            // Current index ko push karo for upcoming elements.
            st.push(i);
        }

        return left;
    }

    int MAH(vector<int>& heights) {
        int n = heights.size();

        // Har bar ke liye nearest smaller boundaries find karo.
        vector<int> right = NSR(heights);
        vector<int> left  = NSL(heights);

        // Har bar ko rectangle ki minimum height maan kar
        // uske maximum possible width se area calculate karenge.
        vector<int> width(n);

        for(int i = 0; i < n; i++)
            // Left aur right boundary wale bars rectangle mein
            // include nahi honge, kyunki unki height smaller hai.
            width[i] = right[i] - left[i] - 1;

        int max_area = 0;

        for(int i = 0; i < n; i++) {

            // Current bar ki height poore calculated width mein
            // rectangle ki minimum height hogi.
            int a = width[i] * heights[i];

            // Maximum area ko update karo agar bada rectangle mila.
            if(max_area < a)
                max_area = a;
        }

        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        // Empty matrix mein koi rectangle nahi ban sakta.
        if(matrix.size() == 0)
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        // Har column ki consecutive '1's ki height store hogi.
        // Initially first row ke according heights banengi.
        vector<int> height(m);

        for(int i = 0; i < m; i++) {
            // First row mein '1' hai toh height 1,
            // warna height 0 se start hogi.
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }

        // First row ke histogram mein maximum rectangle find karo.
        int maxA = MAH(height);

        // Ab remaining rows ko one by one process karenge.
        for(int i = 1; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == '0') {
                    // Zero aane par consecutive ones ka chain toot jata hai,
                    // isliye current column ki height reset kar do.
                    height[j] = 0;
                } else {
                    // One aane par upar wali consecutive height mein 1 add karo.
                    // Is tarah current row tak consecutive ones ki height milegi.
                    height[j] += 1;
                }
            }

            // Current row ko histogram ka base maan kar
            // usmein maximum rectangle find karo.
            maxA = max(maxA, MAH(height));
        }

        // Sabhi rows ke histograms mein se maximum rectangle area return karo.
        return maxA;
    }
};