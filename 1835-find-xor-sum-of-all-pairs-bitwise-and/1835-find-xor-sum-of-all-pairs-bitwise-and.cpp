class Solution {
    void fillCount(vector<int>& arr, vector<int>& count){
        for(int& x: arr){
            for(int i=0; i<31; i++){
                if(x&(1<<i))
                    count[i]++;
            }
        }
    }
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        long long m = arr1.size(), n = arr2.size();
        vector<int> count1(32, 0), count2(32, 0);
        
        fillCount(arr1, count1);
        fillCount(arr2, count2);
        
        int ans = 0;
        for(int i=0; i<31; i++){
            if((count1[i]&1) && (count2[i]&1))
                ans |= (1<<i);
        }
        return ans;
    }
};