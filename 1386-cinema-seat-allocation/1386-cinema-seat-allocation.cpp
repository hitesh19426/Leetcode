class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) -> bool {
            return a[0] < b[0];
        });
        
        int groups[] = {0b111100, 0b11110000, 0b1111000000};
        
        // cout << groups[0] << " " << groups[1] << " " << groups[2] << endl;
        
        
        int start = 0, count = 0, prevRow = 0;
        while(start < arr.size()) {
            count += 2*(arr[start][0] - prevRow - 1);
            prevRow = arr[start][0];
            
            int row = 0;
            int currRow = arr[start][0];
            while(start<arr.size() && arr[start][0] == currRow)
                row |= (1<<arr[start][1]), start++;
            
            int status = 0;
            for(int i=0; i<3; i++){
                // cout << (row&groups[i]) << " ";
                if((row&groups[i]) == 0)
                    status |= 1<<i;
            }
            // cout << endl;
            // cout << " " << row << endl;
            // cout << row << " " << arr[start-1][0] << " " << status << endl << endl;
            
            if(status == 5 || status == 7)
                count += 2;
            else if(status > 0)
                count++;
        }
        
        return count + 2*(n-prevRow);
    }
};