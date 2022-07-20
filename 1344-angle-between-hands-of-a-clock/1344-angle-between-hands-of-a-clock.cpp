class Solution {
public:
    double angleClock(int hour, int minutes) {
        int total_time = (hour%12)*60 + minutes;
        double angle_of_minute = (minutes)*6.0;
        double angle_of_hour = (total_time)/2.0;
        
        // cout << total_time << " " << angle_of_minute << " " << angle_of_hour << endl;
        
        double angle = abs(angle_of_minute-angle_of_hour);
        // while(angle > 180)
        //     angle -= 180;
        return min(angle, 360-angle);
        // return angle;
    }
};