class Solution {
    struct comparator{
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            if(a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        }
    };
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        pq.push({nums[0], nums[0]});
        
        for(int i=1; i<nums.size(); i++){
            bool inserted = false;
            while(!pq.empty()){
                auto top = pq.top();
                if(top.second == nums[i]){
                    pq.push({nums[i], nums[i]});
                    inserted = true;
                    break;
                }
                else if(top.second == nums[i]-1){
                    pq.pop();
                    pq.push({top.first, nums[i]});
                    inserted = true;
                    break;
                }
                else if(top.second - top.first + 1 < 3)
                    return false;
                else
                    pq.pop();
            }
            if(!inserted){
                pq.push({nums[i], nums[i]});
            }
        }
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            if(top.second - top.first + 1 < 3)
                return false;
        }
        
        return true;
    }
};