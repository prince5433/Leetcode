
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        // NEXT SMALLER ELEMENT (INDEX) find kar rahe hain.
        // Har bar ke right side mein pehla strictly smaller height ka index chahiye.
        int nsi[n];
        stack<int> st;

        // Last bar ke right mein koi bar nahi hai, isliye boundary index n rakhenge.
        nsi[n-1]=n;
        st.push(n-1);

        for(int i=n-2;i>=0;i--){

            // Current bar se greater ya equal height wale bars ko pop karo,
            // kyunki woh current bar ke liye next smaller boundary nahi ban sakte.
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }

            // Agar stack empty hai, toh right mein koi smaller bar nahi mila.
            if(st.size()==0) nsi[i]=n;

            // Warna stack top hi next smaller bar ka index hai.
            else nsi[i]=st.top();

            // Current index ko future comparisons ke liye stack mein daalo.
            st.push(i);
        }

        // PREVIOUS SMALLER ELEMENT (INDEX) find kar rahe hain.
        // Har bar ke left side mein pehla strictly smaller height ka index chahiye.
        int psi[n];
        stack<int> st2;

        // First bar ke left mein koi bar nahi hai, isliye boundary -1 hai.
        psi[0]=-1;
        st2.push(0);

        for(int i=1;i<n;i++){

            // Current bar se greater ya equal height wale bars ko pop karo,
            // taaki stack top par previous smaller height mil sake.
            while(st2.size()>0 && heights[st2.top()]>=heights[i]){
                st2.pop();
            }

            // Agar stack empty hai, toh left mein koi smaller bar nahi mila.
            if(st2.size()==0) psi[i]=-1;

            // Warna stack top previous smaller bar ka index hai.
            else psi[i]=st2.top();

            // Current index ko future comparisons ke liye push karo.
            st2.push(i);
        }

        int area;
        int maxarea=INT_MIN;

        for(int i=0;i<n;i++){

            // Current bar ko rectangle ki minimum height maan rahe hain.
            // Width = next smaller index - previous smaller index - 1.
            // Dono smaller bars boundary hain, isliye unhe width mein include nahi karna.
            area=heights[i]*(nsi[i]-psi[i]-1);

            // Ab tak ka maximum area update karo.
            maxarea=max(maxarea,area);
        }

        return maxarea;
    }
};
