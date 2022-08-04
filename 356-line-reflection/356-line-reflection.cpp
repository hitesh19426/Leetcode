class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        map<int, set<int>> xs;
        for(auto &point: points){
            xs[point[1]].insert(point[0]);
        }
        
        int y = INT_MAX;
        for(auto &pair: xs){
            vector<int> arr;
            for(auto &x: pair.second)
                arr.push_back(x);
            int low = 0, high = arr.size()-1;
            while(low <= high){
                if(y == INT_MAX)
                    y = (arr[low]+arr[high]);
                if(y != arr[low] + arr[high])
                    return false;
                low++, high--;
            }
        }
        return true;
    }
};