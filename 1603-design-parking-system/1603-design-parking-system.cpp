class ParkingSystem {
public:
    // b = number of big slots
    // m = number of medium slots
    // s = number of small slots
    int b, m, s;

    // Constructor: initialize parking slots
    ParkingSystem(int big, int medium, int small) {
        b = big;        // store big car slots
        m = medium;     // store medium car slots
        s = small;      // store small car slots
    }
    
    // Function to add a car of given type
    bool addCar(int carType) {

        // If car is BIG type
        if (carType == 1) {
            if (b > 0) {     // check if big slot is available
                b--;         // occupy one big slot
                return true; // car parked successfully
            }
            return false;    // no big slot available
        } 
        
        // If car is MEDIUM type
        else if (carType == 2) {
            if (m > 0) {     // check if medium slot is available
                m--;         // occupy one medium slot
                return true; // car parked successfully
            }
            return false;    // no medium slot available
        } 
        
        // If car is SMALL type
        else {
            if (s > 0) {     // check if small slot is available
                s--;         // occupy one small slot
                return true; // car parked successfully
            }
            return false;    // no small slot available
        }
    }
};
