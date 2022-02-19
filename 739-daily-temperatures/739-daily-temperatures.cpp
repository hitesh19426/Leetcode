class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> biggerFromRight(n);
        
        for(int i=n-1; i>=0; i--){
            int right = i+1;
            while(right < n && temperatures[right] <= temperatures[i]){
                if(biggerFromRight[right] == 0){
                    right = n;
                    break;
                }
                right += biggerFromRight[right];
            }
            biggerFromRight[i] = (right == n ? 0 : right-i);
        }
        
        return biggerFromRight;
    }
    
};