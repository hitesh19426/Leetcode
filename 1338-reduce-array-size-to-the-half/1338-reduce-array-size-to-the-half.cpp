class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> count(100001, 0);
        for(auto &x: arr)
            count[x]++;
        
        sort(count.begin(), count.end(), greater<int>());
        
        int sum = 0, target = arr.size()/2;
        for(int i=0; i<count.size(); i++){
            sum += count[i];
            if(sum >= target)
                return i+1;
        }
        return -1;
    }
};