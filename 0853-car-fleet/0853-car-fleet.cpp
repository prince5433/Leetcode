class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();

        // pair: {position, time to reach target}
        vector<pair<int,double>> cars;

        // Calculate time required for each car to reach target
        for(int i = 0; i < n; i++){
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort cars by position (closest to target last)
        sort(cars.begin(), cars.end());

        int fleets = 0;
        double lastTime = 0;

        // Traverse from the car closest to target
        for(int i = n - 1; i >= 0; i--){

            // If this car takes more time than fleet ahead,
            // it forms a new fleet
            if(cars[i].second > lastTime){
                fleets++;
                lastTime = cars[i].second;
            }

            // Otherwise it joins the fleet ahead
        }

        return fleets;
    }
};