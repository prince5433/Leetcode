class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n=arr.size();
        for(int size=n;size>1;size--){//start sbase bade se kr rhe 
            int idx=0;
            for(int i=0;i<size;i++){
                if(arr[i]==size){//sbse bade k index find kro
                    idx=i;
                    break;
                }
            }
                if(idx==size-1) continue; //agr shi jagah hai to skip 
                if(idx!=0){///agr front pe nhi hai to frione pe lao 
                    res.push_back(idx+1);
                    reverse(arr.begin(),arr.begin()+idx+1);
                }
                res.push_back(size);
                reverse(arr.begin(),arr.begin()+size);
            
        }
        return res;
    }
};