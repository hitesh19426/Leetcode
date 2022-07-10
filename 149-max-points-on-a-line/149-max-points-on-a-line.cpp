class Line{
    int a, b, c;    // ax + by = c
public:
    Line(int a, int b, int c) : a(a), b(b), c(c) {}
    bool operator<(const Line& other) const {
        if(a != other.a)
            return a < other.a;
        if(b != other.b)
            return b < other.b;
        return c < other.c;
    }
    bool checkPoint(int x, int y) const {
        return a*x + b*y == c;
    }
};
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2)
            return points.size();
        
        set<Line> lines;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                // cout << i << " " << j << endl;
                // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                lines.insert(Line(y1-y2, x2-x1, x2*y1-x1*y2));
            }
        }
        
        int ans = 0;
        for(auto &line: lines){
            int pointOnCurrentLine = 0;
            for(int i=0; i<points.size(); i++){
                pointOnCurrentLine += line.checkPoint(points[i][0], points[i][1]);
            }
            ans = max(ans, pointOnCurrentLine);
        }
        return ans;
    }
};