class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int count[32] = {};
        for(int &x: candidates)
            for(int i=0; i<31; i++)
                if(x&(1<<i))
                    count[i]++;
        
        return *max_element(count, count+32);
    }
};