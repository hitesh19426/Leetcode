class Solution {
    bool dfs(int ind, vector<int>& arr, vector<int>& sides, int target){
        if(ind == arr.size()){
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        
//         for(int x: sides)
//             cout << x << " ";
//         cout << endl;
        
        for(int i=0; i<=3; i++){
            if(arr[ind] + sides[i] > target)
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
        return dfs(0, arr, sides, sum/4);
    }
};