class Solution {
    bool check(string &s, string &p, int mid, vector<int>& index){
        int sp = 0, pp = 0;
        while(sp < s.size() && pp < p.size()){
            if(index[sp] < mid)
                sp++;
            else if(s[sp] == p[pp])
                sp++, pp++;
            else
                sp++;
        }
        return pp == p.size();
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        vector<int> index(s.size(), INT_MAX);
        for(int i=0; i<removable.size(); i++)
            index[removable[i]] = i;
        
        int low = 0, high = removable.size(), ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(s, p, mid, index))
                ans = mid, low = mid+1;
            else
                high = mid-1;
        }
        return ans;
    }
};