class Solution {
public:
    bool check(vector<int>& arr, double mid, int k){
        int count = 0;
        for(int i=0; i<arr.size()-1; i++){
            count += int(ceil((arr[i+1]-arr[i])/mid))-1;
        }
        return count <= k;
    }
    
    double minmaxGasDist(vector<int>& stations, int k) {
        double low = 0, high = stations.back(), epsilon = 1e-6, ans = -1;
        for(int i=0; i<50; i++){
            double mid = (low+high)/2;
            if(check(stations, mid, k))
                ans = mid, high = mid;
            else
                low = mid;
        }
        
        return ans;
    }
};