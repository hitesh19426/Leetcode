class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        for(int i=0; i<intervals.size(); i++)
            intervals[i].push_back(i);
        sort(intervals.begin(), intervals.end());
        
        vector<int> rightside(intervals.size(), -1);
        for(int i=0; i<intervals.size(); i++){
            int low = i, high = intervals.size()-1, ans = -1;
            while(low <= high){
                int mid = (low+high)/2;
                if(intervals[mid][0] >= intervals[i][1])
                    ans = intervals[mid][2], high = mid-1;
                else
                    low = mid+1;
            }
            rightside[intervals[i][2]] = ans;
        }
        
        return rightside;
    }
};