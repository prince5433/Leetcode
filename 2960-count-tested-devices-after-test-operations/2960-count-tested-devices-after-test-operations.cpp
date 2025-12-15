class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int cnt = 0;
        int i = 0;

        while (i < n) {
            // If current device has battery > 0
            if (batteryPercentages[i] > 0) {
                cnt++;   // we test this device

                // After testing, all next devices lose 1% battery
                for (int j = i + 1; j < n; j++) {
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                }
            }
            i++;
        }
        return cnt;
    }
};
