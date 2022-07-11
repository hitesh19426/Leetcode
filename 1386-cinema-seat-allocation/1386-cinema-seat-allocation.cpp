class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
        unordered_map<int, int> rows;
        for(auto& pair: arr)
            rows[pair[0]] |= (1<<pair[1]);
        
        int groups[] = {0b111100, 0b11110000, 0b1111000000};
        int count = 0, countRow = 0;
        for(auto [row, value]: rows){
            int curr = 0;
            if((value&groups[0]) == 0)
                curr++;
            if((value&groups[2]) == 0)
                curr++;
            if((value&groups[1]) == 0 && curr == 0)
                curr = 1;
            
            count += curr, countRow++;
        }
        
        return count + 2*(n-countRow);
    }
};