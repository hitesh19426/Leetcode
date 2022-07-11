class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) -> bool {
            return a[0] < b[0];
        });
        
        int groups[][4] = {{2,3,4,5},{4,5,6,7},{6,7,8,9}};
        
        int start = 0, count = 0, prevRow = 0;
        while(start < arr.size()) {
            count += 2*(arr[start][0] - prevRow - 1);
            prevRow = arr[start][0];
            
            bool row[11] = {};
            int end = start;
            while(end<arr.size() && arr[end][0] == arr[start][0])
                row[arr[end++][1]] = true;
            
            bool status[3] = {};
            for(int i=0; i<3; i++){
                bool done = true;
                for(int j=0; j<4; j++){
                    if(row[groups[i][j]])
                        done = false;
                }
                status[i] = done;
            }
            
            if(status[0] == status[2] && status[0])
                count += 2;
            else if(status[0] || status[1] || status[2])
                count++;
            
            start = end;
        }
        
        return count + 2*(n-prevRow);
    }
};