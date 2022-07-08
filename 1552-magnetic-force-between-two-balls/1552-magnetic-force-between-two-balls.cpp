class Solution {
    bool check(vector<int>& pos, int min_dist, int balls){
        int count = 1, last = pos[0];
        for(int i=1; i<pos.size(); i++){
            if(pos[i] - last >= min_dist){
                last = pos[i];
                count++;
            }
        }
        return count >= balls;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1, high = position.back()-position[0], ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(position, mid, m))
                ans = mid, low = mid+1;
            else
                high = mid-1;
        }
        return ans;
    }
};