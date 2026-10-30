class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> nge(n);
       stack<int> st;
       
    nge[n-1]=0;
     st.push(n-1);
      for(int i=n-2;i>=0;i--){
          while(st.size()>0 && temperatures[st.top()]<=temperatures[i]){
            st.pop();
        }
         if(st.size()==0) nge[i]=0;
          else nge[i]=st.top()-i;
        
        st.push(i);
      }
      return nge;
    }
};



   
