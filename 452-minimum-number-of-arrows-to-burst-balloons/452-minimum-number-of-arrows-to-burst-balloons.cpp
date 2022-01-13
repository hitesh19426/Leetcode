class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) -> bool {
            return a[1] < b[1];
        });
        
        int count = 1, start = points[0][0], end = points[0][1];
        for(int i=1; i<(int)points.size(); i++){
            if(points[i][0] > end){
                end = points[i][1];
                count++;
            }
        }
        return count;
    }
};