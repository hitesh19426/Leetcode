class Solution {
    void insert(multiset<int>& minset, multiset<int>& maxset, int x){
        if(minset.size() == maxset.size()){
            minset.insert(x);
            maxset.insert(*minset.rbegin());
            minset.erase(minset.find(*minset.rbegin()));
        }
        else{
            maxset.insert(x);
            minset.insert(*maxset.begin());
            maxset.erase(maxset.begin());
        }
    }
public:
    vector<double> medianSlidingWindow(vector<int>& arr, int k) {
        int maxs=0, mins=0, n = arr.size();
        multiset<int> maxset, minset;
        if(k&1)
            maxs = k/2+1, mins=k/2;
        else
            maxs = mins = k/2;

        // for(int i=0; i<maxs; i++)
        //     maxset.insert(arr[i]);
        // for(int i=maxs; i<k; i++){
        //     if(arr[i] <= *maxset.begin()){
        //         minset.insert(arr[i]);
        //     }
        //     else{
        //         maxset.insert(arr[i]);
        //         minset.insert(*maxset.begin());
        //         maxset.erase(maxset.begin());
        //     }
        // }
        for(int i=0; i<k; i++){
            insert(minset, maxset, arr[i]);
        }
 
        vector<double> ans;
        for(int i=0; i+k-1<n; i++){
            if(i!=0){
                auto itr = maxset.find(arr[i-1]);
                if(itr == maxset.end()){
                    minset.erase(minset.find(arr[i-1]));
                }
                else{
                    maxset.erase(itr);
                    if(!minset.empty()){
                        int prev = *minset.rbegin();
                        maxset.insert(prev);
                        minset.erase(minset.find(prev));
                    }
                }

                if((int)maxset.size() < maxs){
                    maxset.insert(arr[i+k-1]);
                }
                else if(arr[i+k-1] <= *maxset.begin()){
                    minset.insert(arr[i+k-1]);
                }
                else{
                    maxset.insert(arr[i+k-1]);
                    minset.insert(*maxset.begin());
                    maxset.erase(maxset.begin());
                }

            }

            double median = (k&1 ? *maxset.begin() : ((double)*minset.rbegin() + *maxset.begin())/2.0 );
            ans.push_back(median);
        }
        
        return ans;
    }
};