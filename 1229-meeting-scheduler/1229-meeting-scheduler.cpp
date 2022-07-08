class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slot1, vector<vector<int>>& slot2, int duration) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto &interval: slot1){
            if(interval[1] - interval[0] >= duration)
                pq.push({interval[0], interval[1]});
        }
        
        for(auto &interval: slot2){
            if(interval[1] - interval[0] >= duration)
                pq.push({interval[0], interval[1]});
        }
        
        while(pq.size() > 1){
            auto end1 = pq.top().second;
            pq.pop();
            auto start2 = pq.top().first;
            
            if(end1 >= start2 + duration)
                return {start2, start2 + duration};
        }
        
        return {};
    }
};