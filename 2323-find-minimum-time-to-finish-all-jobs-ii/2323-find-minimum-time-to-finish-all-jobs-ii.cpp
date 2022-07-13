class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        priority_queue<int> workers_pq(workers.begin(), workers.end());
        priority_queue<int> jobs_pq(jobs.begin(), jobs.end());
        
        int ans = 0;
        while(!jobs_pq.empty()){
            ans = max(ans, jobs_pq.top()/workers_pq.top() + (jobs_pq.top()%workers_pq.top() != 0));
            jobs_pq.pop();
            workers_pq.pop();
        }
        
        return ans;
    }
};