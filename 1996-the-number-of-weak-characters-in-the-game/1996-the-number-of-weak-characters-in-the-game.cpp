class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) -> bool {
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        
        int maxDefence = 0, count = 0;
        for(int i=arr.size()-1; i>=0; i--){
            if(maxDefence > arr[i][1])
                count++;
            maxDefence = max(maxDefence, arr[i][1]);
        }
        
        return count;
    }
};