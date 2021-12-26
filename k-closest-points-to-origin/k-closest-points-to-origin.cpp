class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin()+k, points.end(), [](const vector<int>& point1, const vector<int>& point2) -> bool {
           return (point1[0]*point1[0] + point1[1]*point1[1]) < (point2[0]*point2[0] + point2[1]*point2[1]);
        });
        
        vector<vector<int>> ans;
        for(int i=0; i<k; i++)
            ans.push_back(points[i]);
        return ans;
    }
};