class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> arr;
        for(int i=0; i<n; i++){
            if(seats[i] == 1)
                arr.push_back(i);
        }
        
        int distance = max(arr[0], n-1-arr.back());
        for(int i=0; i<(int)arr.size()-1; i++){
            distance = max(distance, (arr[i+1] - arr[i])/2);
        }
        
        return distance;
    }
};