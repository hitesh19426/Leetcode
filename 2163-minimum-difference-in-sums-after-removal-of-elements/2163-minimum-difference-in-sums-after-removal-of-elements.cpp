class Solution {
public:
    long long minimumDifference(vector<int>& arr) {
        int n = arr.size(), k = n/3;
        multiset<int> left(arr.begin(), arr.begin()+k);

        long long left_sum = accumulate(arr.begin(), arr.begin()+k, 0ll);

        multiset<int> higher(arr.begin()+k, arr.begin()+2*k), lower;
        long long high_sum = accumulate(arr.begin()+k, arr.begin()+2*k, 0ll), low_sum = 0ll;

        for(int i=2*k; i<n; i++){
            higher.insert(arr[i]);
            high_sum += arr[i];

            lower.insert(*higher.begin());
            low_sum += *higher.begin();

            high_sum -= *higher.begin();
            higher.erase(higher.begin());
        }

        long long ans = left_sum - high_sum;
        for(int i=k; i<2*k; i++){
            if(lower.find(arr[i]) != lower.end()){
                lower.erase(lower.find(arr[i]));
            }
            else{
                high_sum -= arr[i];
                higher.erase(higher.find(arr[i]));

                high_sum += *lower.rbegin();
                higher.insert(*lower.rbegin());
                lower.erase(lower.find(*lower.rbegin()));
            }

            left.insert(arr[i]);
            left_sum += arr[i];

            left_sum -= *left.rbegin();
            left.erase(left.find(*left.rbegin()));

            ans = min(ans, left_sum - high_sum);
        }

        return ans;
    }
};