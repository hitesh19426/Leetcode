class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        
        int m = firstList.size(), n = secondList.size(), i = 0,  j = 0;
        while(i<m && j<n){
            if(firstList[i][1] < secondList[j][0]){
                i++;
            }
            else if(firstList[i][0] > secondList[j][1]){
                j++;
            }
            else{
                auto point = {max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])};
                ans.push_back(point);
                if(firstList[i][1] < secondList[j][1])
                    i++;
                else j++;
            }
        }
        return ans;
    }
};