class SparseVector {
    vector<pair<int, int>> arr;
public:
    SparseVector(vector<int> &nums) {
        for(int i=0; i<nums.size(); i++)
            arr.push_back({i, nums[i]});
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i = 0, j = 0, ans = 0;
        while(i<arr.size() && j<vec.arr.size()){
            if(arr[i].first < vec.arr[j].first)
                i++;
            else if(arr[i].first > vec.arr[j].first)
                j++;
            else
                ans += arr[i++].second*vec.arr[j++].second;
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);