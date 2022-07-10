bool checkPoint(const vector<int>& line, int x, int y) {
    return line[0]*x + line[1]*y == line[2];
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2)
            return points.size();
        
        set<vector<int>> lines;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                lines.insert({y1-y2, x2-x1, x2*y1-x1*y2});
            }
        }
        
        int ans = 0;
        for(auto &line: lines){
            int pointOnCurrentLine = 0;
            for(int i=0; i<points.size(); i++){
                pointOnCurrentLine += checkPoint(line, points[i][0], points[i][1]);
            }
            ans = max(ans, pointOnCurrentLine);
        }
        return ans;
    }
};