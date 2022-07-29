class Solution {
    void fillCount(vector<int>& arr, int count[32]){
        for(int i=0; i<31; i++){
            for(int& x: arr){
                if(x&(1<<i))
                    count[i]++;
            }
        }
    }
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int count1[32] = {}, count2[32] = {};
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