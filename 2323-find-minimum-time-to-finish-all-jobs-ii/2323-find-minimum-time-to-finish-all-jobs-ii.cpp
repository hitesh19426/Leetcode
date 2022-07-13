class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        sort(workers.begin(), workers.end());
        sort(jobs.begin(), jobs.end());
        
        int ans = 0;
        for(int i=0; i<jobs.size(); i++)
            ans = max(ans, jobs[i]/workers[i] + (jobs[i]%workers[i] != 0));
        
        return ans;
    }
};