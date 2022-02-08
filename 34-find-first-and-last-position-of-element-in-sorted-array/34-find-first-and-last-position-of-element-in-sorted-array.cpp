class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        if(!binary_search(arr.begin(), arr.end(), target))
            return {-1, -1};
        auto lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        auto ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        return {(int)lb, (int)ub-1};
    }
};