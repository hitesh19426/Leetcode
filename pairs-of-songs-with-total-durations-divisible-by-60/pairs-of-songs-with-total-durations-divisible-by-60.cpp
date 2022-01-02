class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> count;
        for(int x:time){
            count[x%60]++;
        }
        
        int ans = (count[0]*(count[0]-1))/2 + (count[30]*(count[30]-1))/2;
        for(int i=1; i<30; i++)
            ans += count[i]*count[60-i];
        
        return ans;
    }
};