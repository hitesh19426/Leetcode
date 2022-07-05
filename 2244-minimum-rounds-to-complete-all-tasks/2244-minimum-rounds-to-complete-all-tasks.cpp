class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> count;
        for(auto &task: tasks)
            count[task]++;
        
        int ans = 0;
        for(auto &[key, value]: count){
            if(value == 1)
                return -1;
            ans += value/3 + (value%3!=0);
        }
        return ans;
    }
};