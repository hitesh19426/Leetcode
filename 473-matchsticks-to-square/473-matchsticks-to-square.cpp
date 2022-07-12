class Solution {
    bool dfs(int ind, vector<int>& arr, vector<int>& sides, int target){
        if(ind == arr.size()){
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        
        for(int i=0; i<4; i++){
            if(arr[ind] + sides[i] > target)
                continue;
            bool dont = false;
            for(int j=0; j<i; j++){
                if(sides[j] == sides[i])
                    dont = true;
            }
            if(dont)
                continue;
            sides[i] += arr[ind];
            if(dfs(ind+1, arr, sides, target))
                return true;
            sides[i] -= arr[ind];
        }
        
        return false;
    }
public:
    bool makesquare(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum%4)
            return false;
                
        vector<int> sides(4, 0);
        sort(arr.begin(), arr.end(), greater<int>());
        if(arr[0] > sum/4)
            return false;
        return dfs(0, arr, sides, sum/4);
    }
};