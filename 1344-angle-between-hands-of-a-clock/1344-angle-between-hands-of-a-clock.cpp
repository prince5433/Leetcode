class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min_angle=minutes*6;
        double hour_angle=(hour%12)*30+minutes*0.5;

        double diff=abs(min_angle-hour_angle);
        return min(diff,360-diff);
    }
};