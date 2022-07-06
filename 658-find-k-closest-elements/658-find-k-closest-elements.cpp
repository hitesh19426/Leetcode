class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right-1;
        
        int count = k, n = arr.size();
        vector<int> ans;
        while(right < n && left >=0 && count--){
            if(abs(arr[left]-x) <= abs(arr[right]-x))
                left--;
            else
                right++;
        }
        
        while(left>=0 && count>0)
            left--, count--;
        while(right < n && count>0)
            right++, count--;
        
        return vector<int> (arr.begin()+left+1, arr.begin()+right);
    }
};