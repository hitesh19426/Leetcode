class Solution {
public:
    long long minimumDifference(vector<int>& arr) {
        int n = arr.size(), k = n/3;
        priority_queue<int> left(arr.begin(), arr.begin()+k);
        long long left_sum = accumulate(arr.begin(), arr.begin()+k, 0ll);

        map<int, int> higher, lower;
        for(int i=k; i<2*k; i++)
            higher[arr[i]]++;
        long long high_sum = accumulate(arr.begin()+k, arr.begin()+2*k, 0ll);

        for(int i=2*k; i<n; i++){
            higher[arr[i]]++;
            auto itr = higher.begin();
            high_sum += arr[i] - itr->first;
            
            lower[itr->first]++;
            if(--higher[itr->first] == 0)
                higher.erase(itr);
        }

        long long ans = left_sum - high_sum;
        for(int i=k; i<2*k; i++){
            if(lower.find(arr[i]) != lower.end()){
                if(--lower[arr[i]] == 0)
                    lower.erase(arr[i]);
            }
            else{
                high_sum -= arr[i];
                
                auto itr = lower.rbegin();
                if(--higher[arr[i]] == 0)
                    higher.erase(arr[i]);

                high_sum += itr->first;
                higher[itr->first]++;
                if(--lower[itr->first] == 0)
                    lower.erase(itr->first);
            }

            left.push(arr[i]);
            left_sum += arr[i] -  left.top();
            left.pop();

            ans = min(ans, left_sum - high_sum);
        }

        return ans;
    }
};