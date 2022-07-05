class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> arr;
        for(int i=0; i<plantTime.size(); i++){
            arr.push_back({growTime[i], plantTime[i]});
        }
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        
        int end = 0, maxTime = 0;
        for(int i=0; i<arr.size(); i++){
            end += arr[i].second;
            maxTime = max(maxTime, end + arr[i].first);
        }
        return maxTime;
    }
};