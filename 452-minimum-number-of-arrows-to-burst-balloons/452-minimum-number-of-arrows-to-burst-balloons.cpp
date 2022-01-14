class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int count = 1, end = points[0][1];
        for(int i=1; i<(int)points.size(); i++){
            if(points[i][0] > end){
                end = points[i][1];
                count++;
            }
            else{
                end = min(end, points[i][1]);
            }
        }
        return count;
    }
};