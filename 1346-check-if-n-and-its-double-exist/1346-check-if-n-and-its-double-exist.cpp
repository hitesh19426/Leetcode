class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int x: arr)
            count[x]++;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 0 && count[0] > 1)
                return true;
            if(arr[i] != 0 && count.find(2*arr[i]) != count.end())
                return true;
        }
        return false;
    }
};