class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        // n = array ka size
        int n = nums.size();

        // ans = count of dominant indices
        int ans = 0;

        /*
          Prefix sum array:
          pre[i] = nums[0] se nums[i] tak ka sum

          Isse hume total sum ya kisi range ka sum
          O(1) time me mil jata hai
        */
        vector<int> pre(n, 0);
        pre[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }

        /*
          Loop n-1 tak:
          kyunki last index ke baad koi element nahi hota
          jiska average nikal sake
        */
        for (int i = 0; i < n - 1; i++) {

            /*
              totalSum = pre[n-1]

              baaki elements ka sum (i ke baad wale):
              = totalSum - pre[i]

              i ke baad elements ki count:
              = n - i - 1

              baaki elements ka average:
              = (totalSum - pre[i]) / (n - i - 1)

              Condition:
              agar nums[i] > baaki elements ke average se
              to ye index dominant maana jayega
            */
            if (nums[i] > (pre[n - 1] - pre[i]) / (n - i - 1))
                ans++;
        }

        // total dominant indices return
        return ans;
    }
};
