struct Prefix_DS{
    int maxi, issorted;
    Prefix_DS(int maxi, int issorted) : maxi(maxi), issorted(issorted) {}
};

struct Suffix_DS{
    int mini, issorted;
    Suffix_DS() : mini(INT_MAX), issorted(true) {}
    Suffix_DS(int mini, int issorted) : mini(mini), issorted(issorted) {}
};

class Solution {
    bool check(vector<Prefix_DS>& prefix, vector<Suffix_DS> &suffix, int mid){
        int n = prefix.size()-1;
        for(int i=0, j=mid-1; j<n; i++, j++){
            if(prefix[i].issorted && suffix[j+1].issorted && prefix[i].maxi <= suffix[j+1].mini)
                return true;
        }
        return false;
    }
    
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        vector<Prefix_DS> prefix;
        prefix.push_back({INT_MIN, true});
        for(int i=0; i<arr.size(); i++){
            bool prefix_is_sorted = (prefix.back().issorted && arr[i] >= prefix.back().maxi);
            prefix.push_back({max(prefix.back().maxi, arr[i]), prefix_is_sorted});
        }
        
        vector<Suffix_DS> suffix(arr.size()+1);
        for(int i=arr.size()-1; i>=0; i--){
            bool suffix_is_sorted = (suffix[i+1].issorted && suffix[i+1].mini >= arr[i]);
            suffix[i] = {min(suffix[i+1].mini, arr[i]), suffix_is_sorted};
        }
        
        int low = 0, high = arr.size()-1, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(prefix, suffix, mid))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};