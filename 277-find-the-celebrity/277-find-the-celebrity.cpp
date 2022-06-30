/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> candidates;
        for(int i=0; i<n; i++)
            candidates.push_back(i);
        
        while(candidates.size() > 1){
            int curr = candidates.back();
            candidates.pop_back();
            
            if(knows(candidates.back(), curr)){
                candidates.pop_back();
                candidates.push_back(curr);
            }
        }
        
        // cout << candidates[0] << endl;
        for(int i=0; i<n; i++){
            if(i == candidates[0])
                continue;
            if(knows(candidates[0], i) || !knows(i, candidates[0]))
                return -1;
        }
        return candidates[0];
    }
};