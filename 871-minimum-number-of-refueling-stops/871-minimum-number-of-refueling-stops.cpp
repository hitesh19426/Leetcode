class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        
        priority_queue<int> pq;
        int fuelLeft = startFuel, prev = 0, count = 0;
        
        for(int i=0; i<stations.size(); i++){
            while(!pq.empty() && fuelLeft < stations[i][0] - prev){
                count++;
                fuelLeft += pq.top();
                pq.pop();
            }
            if(fuelLeft < stations[i][0] - prev)
                return -1;
            
            fuelLeft -= stations[i][0] - prev;
            prev = stations[i][0];
            pq.push(stations[i][1]);
        }
        
        return count;
    }
};