class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b) -> bool {
            return a[1] > b[1];
        });
        
        int res = 0, count = 0;
        for(auto& box: boxTypes){
            if(count + box[0] <= truckSize){
                res += box[0]*box[1];
                count += box[0];
            }
            else{
                res += (truckSize-count)*box[1];
                break;
            }
        }
        
        return res;
    }
};