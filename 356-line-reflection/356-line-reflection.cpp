class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        map<int, set<int>> xs;
        for(auto &point: points){
            xs[point[1]].insert(point[0]);
        }
        
        int y = INT_MAX;
        for(auto &pair: xs){
            auto low = pair.second.begin();
            auto high = pair.second.rbegin();
            if(y == INT_MAX)
                y = *low + *high;
            while(low != pair.second.end() && high != pair.second.rend() && *low <= *high){
                if(y != *low + *high)
                    return false;
                low++, high++;
            }
        }
        return true;
    }
};