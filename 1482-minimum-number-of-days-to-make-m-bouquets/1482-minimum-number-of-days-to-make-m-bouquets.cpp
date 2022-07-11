class Solution {
    bool check(vector<int>& arr, int day, int req, int k){
        int count = 0, bouquet = 0, start = -1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > day){
                count = 0;
            }
            else{
                count++;
                if(count == k)
                    bouquet++, count = 0;
            }
        }
        return bouquet >= req;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end()), ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(check(bloomDay, mid, m, k))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};