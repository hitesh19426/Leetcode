class Solution {
    int distance(vector<int>& pt1, vector<int>& pt2){
        return ((pt1[0] - pt2[0])*(pt1[0] - pt2[0]) + (pt1[1] - pt2[1])*(pt1[1] - pt2[1]));
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points{p1, p2, p3, p4};
        
        for(auto &pt1: points){
            map<int, int> dist;
            for(auto &pt2: points){
                if(pt1 != pt2){
                    dist[distance(pt1, pt2)]++;
                }
            }
            if(dist.size() != 2 || dist.begin()->second != 2)
                return false;
            if(dist.rbegin()->first != 2*dist.begin()->first)
                return false;
        }
        
        return true;
    }
};