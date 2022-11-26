struct Job{
    int start, end, profit;
    Job(int start, int end, int profit) : start(start), end(end), profit(profit) {}
    bool operator<(const Job& other){
        return end < other.end;
    }
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;
        int n = endTime.size();
        for(int i=0; i<n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        vector<int> dp(n);
        dp[0] = jobs[0].profit;
        for(int i=1; i<n; i++){
            int low = 0, high = i-1, ind = -1;
            while(low <= high){
                int mid = (low+high)/2;
                if(jobs[mid].end <= jobs[i].start)
                    ind = mid, low = mid+1;
                else
                    high = mid-1;
            }
            
            int prev = (ind == -1 ? 0 : dp[ind]);
            dp[i] = max(dp[i-1], prev + jobs[i].profit);
        }
        
        return dp.back();
    }
};