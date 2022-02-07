mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Solution {
public:
    vector<int> prefix;
    int sum = 0;
    Solution(vector<int>& w) {
        for(int i=0; i<w.size(); i++){
            sum += w[i];
            if(i == 0)
                prefix.push_back(w[i]-1);
            else
                prefix.push_back(prefix.back()+w[i]);
        }
    }
    
    int pickIndex() {
        int index = rng()%sum;
        return lower_bound(prefix.begin(), prefix.end(), index) - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */