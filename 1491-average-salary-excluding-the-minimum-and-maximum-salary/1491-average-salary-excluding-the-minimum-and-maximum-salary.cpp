class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();

        sort(salary.begin(), salary.end());          // sort so min = salary[0], max = salary[n-1]

        long long sum = 0;                           // sum of middle elements (avoid overflow)

        for(int i = 1; i < n - 1; i++){              // exclude min and max
            sum += salary[i];
        }

        return (double)sum / (n - 2);                // average of remaining (n-2) salaries
    }
};
