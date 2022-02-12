class Solution {
public: 
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        while(arr.size()>1u){
            int n = arr.size();
            int index = min_element(arr.begin(), arr.end()) - arr.begin();
            
            int sidenode;
            if(index-1 < 0)
                sidenode = index+1;
            else if(index+1>=n)
                sidenode = index-1;
            else if(arr[index-1] < arr[index+1])
                sidenode = index-1;
            else
                sidenode = index+1;
            
            ans += arr[index]*arr[sidenode];
            arr[index] = max(arr[index], arr[sidenode]);
            arr.erase(arr.begin()+sidenode);
        }
        
        return ans;
    }
};