class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2)
            return points.size();
        
        int count = 0, ans = 1;
        for(int i=0; i<points.size(); i++){
            map<pair<int, int>, int> slopes;
            for(int j=i+1; j<points.size(); j++){
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                int gcd = __gcd(abs(y2-y1), abs(x2-x1));
                int num = (y2-y1)/gcd, dem = (x2-x1)/gcd;
                if(dem<0)
                    num = -num, dem = -dem;
                if(dem == 0)
                    num = 1;
                
                pair<int, int> slope{num, dem};
                // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                // cout << num << " " << dem << endl; 
                if(slopes.find(slope) == slopes.end())
                    slopes[slope] = 2;
                else
                    slopes[slope]++;
                ans = max(ans, slopes[slope]);
            }
            // cout << endl;
        }
        
        return ans;
    }
};