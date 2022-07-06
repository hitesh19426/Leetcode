class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right-1;
        
        int count = k, n = arr.size();
        vector<int> ans;
        while(right < n && left >=0 && count>0){
            if(abs(arr[left]-x) <= abs(arr[right]-x))
                ans.push_back(arr[left--]);
            else
                ans.push_back(arr[right++]);
            count--;
        }
        
        while(left>=0 && count>0){
            ans.push_back(arr[left--]);
            count--;
        }
        while(right < n && count){
            ans.push_back(arr[right++]);
            count--;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};