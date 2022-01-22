class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        int lastseat = -1, distance = 0;
        for(int i=0; i<(int)seats.size(); i++){
            if(seats[i] == 1){
                if(lastseat == -1){
                    distance = max(distance, i);
                }
                else{
                    distance = max(distance, (i - lastseat)/2);
                }
                lastseat = i;
            }
        }
        distance = max(distance, n-1-lastseat);
        return distance;
    }
};