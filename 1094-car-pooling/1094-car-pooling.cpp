class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> arrival, departure;
        for(int i=0; i<(int)trips.size(); i++){
            arrival.push_back({trips[i][1], trips[i][0]});
            departure.push_back({trips[i][2], trips[i][0]});
        }
        
        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());
        
        int arr = 0, dep = 0, n = trips.size(), count = 0;
        while(arr < n){
            if(arrival[arr][0] < departure[dep][0]){
                count += arrival[arr][1];
                if(count > capacity)
                    return false;
                arr++;
            }
            else{
                count -= departure[dep][1];
                dep++;
            }
        }
        
        return true;
    }
};