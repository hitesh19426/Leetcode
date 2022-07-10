class Solution {
    bool check(vector<int>& dist, int mid, double hour){
        double time = 0;
        for(int i=0; i<dist.size()-1; i++){
            time += ceil((double)dist[i]/mid);
        }
        time += (double)dist.back()/mid;
        return time <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int low = 1, high = INT_MAX-5, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(dist, mid, hour))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};