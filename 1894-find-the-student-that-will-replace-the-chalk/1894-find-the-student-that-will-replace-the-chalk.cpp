class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total_sum = accumulate(chalk.begin(), chalk.end(), 0ll);
        long long rem = (long long)k%total_sum;
        
        for(int i=0; i<chalk.size(); i++){
            rem -= chalk[i];
            if(rem < 0)
                return i;
        }
        return -1;
    }
};