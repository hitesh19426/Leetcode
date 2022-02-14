class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 0)
                continue;
            int k = i+2;
            for(int j=i+1; j<arr.size(); j++){
                while(k<arr.size() && arr[k] < arr[i]+arr[j])
                    k++;
                ans += k-j-1;
            }
        }
        return ans;
    }
};