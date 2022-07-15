class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {    
        sort(worker.begin(), worker.end());
        
        vector<pair<int, int>> jobs;
        for(int i=0; i<profit.size(); i++)
            jobs.push_back({difficulty[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        
        int ind = 0, max_profit = 0, ans = 0;
        for(auto& w: worker){
            while(ind < jobs.size() && jobs[ind].first <= w)
                max_profit = max(max_profit, jobs[ind].second), ind++;
            ans += max_profit;
        }
        
        return ans;
    }
};