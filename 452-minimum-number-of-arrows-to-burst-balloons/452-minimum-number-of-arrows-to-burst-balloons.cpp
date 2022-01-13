class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int count = 1, currentEnd = points[0][1], n = points.size();
        for(int i=1; i<n; i++){
            if(points[i][0] > currentEnd){
                currentEnd = points[i][1];
                count++;
            }
            else{
                currentEnd = min(currentEnd, points[i][1]);
            }
        }
        return count;
    }
};