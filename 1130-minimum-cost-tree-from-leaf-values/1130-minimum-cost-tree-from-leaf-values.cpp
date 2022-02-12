class Solution {
public: 
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        while(arr.size()>1u){
            int n = arr.size();
            int index = min_element(arr.begin(), arr.end()) - arr.begin();
            
            int sidenode;
            if(0 < index && index < n-1)
                sidenode = (arr[index-1] < arr[index+1] ? index-1 : index+1);
            else
                sidenode = (index ? index-1 : index+1);
            
            ans += arr[index]*arr[sidenode];
            arr.erase(arr.begin()+index);
        }
        
        return ans;
    }
};