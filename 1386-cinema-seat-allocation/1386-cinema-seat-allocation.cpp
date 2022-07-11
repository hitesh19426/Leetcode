class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) -> bool {
            return a[0] < b[0];
        });
        
        int groups[] = {0b111100, 0b11110000, 0b1111000000};
        
        int start = 0, count = 0, countRow = 0;
        while(start < arr.size()) {
            int row = 0, currRow = arr[start][0];
            while(start<arr.size() && arr[start][0] == currRow)
                row |= (1<<arr[start++][1]);
            
            int curr = 0;
            if((row&groups[0]) == 0)
                curr++;
            if((row&groups[2]) == 0)
                curr++;
            if((row&groups[1]) == 0 && curr == 0)
                curr = 1;
            
            count += curr, countRow++;
        }
        
        return count + 2*(n-countRow);
    }
};