class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int maxDefence[n];
        for(int i=n-1; i>=0; i--){
            maxDefence[i] = (i == n-1 ? arr[i][1] : max(maxDefence[i+1], arr[i][1]));
        }
        
        int ind = 0, count = 0;
        for(int i=0; i<n; i++){
            while(ind < n && arr[ind][0] <= arr[i][0])
                ind++;
            if(ind < n && maxDefence[ind] > arr[i][1])
                count++;
        }
        
        return count;
    }
};