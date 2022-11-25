class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>=0 && binary_search(arr.begin()+i+1, arr.end(), 2*arr[i]))
                return true;
            if(arr[i]<0 && binary_search(arr.begin(), arr.begin()+i, 2*arr[i]))
                return true;
        }
        return false;
    }
};