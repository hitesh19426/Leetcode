class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> count;
        for(auto &x: arr)
            count[x]++;
        
        vector<int> freq;
        for(auto &[x, f]: count)
            freq.push_back(f);
        sort(freq.begin(), freq.end(), greater<int>());
        
        int sum = 0, target = arr.size()/2;
        for(int i=0; i<freq.size(); i++){
            sum += freq[i];
            if(sum >= target)
                return i+1;
        }
        return -1;
    }
};