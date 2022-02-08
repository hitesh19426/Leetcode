class Solution {
public:
    bool check(vector<int>& arr, int min_sweet, int k){
        int sum = 0, count = 0;
        for(int val: arr){
            if(sum + val < min_sweet)
                sum += val;
            else
                sum = 0, count++;
        }
        
        return count >= k+1;
    }
    
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int low = 1, high = 0, ans = -1;
        for(int sweet: sweetness)
            high += sweet;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(sweetness, mid, k))
                ans = mid, low = mid+1;
            else
                high = mid-1;
        }
        
        return ans;
    }
};

/*
max total sweetness = T T T .. T F F F ... 
*/