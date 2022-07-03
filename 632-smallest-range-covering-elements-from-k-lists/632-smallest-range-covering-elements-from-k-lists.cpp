struct Node{
    int index, list_index, value;
    Node(int a, int b, int v) : index(a), list_index(b), value(v) {}
};

struct comparator{
    bool operator()(const Node& a, const Node& b){
        return a.value > b.value;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node, vector<Node>, comparator> minheap;
        
        for(int i=0; i<nums.size(); i++){
            minheap.push(Node(i, 0, nums[i][0]));
        }
        
        vector<pair<int, int>> arr;
        while(!minheap.empty()){
            auto [index, list_index, value] = minheap.top();
            minheap.pop();
            
            arr.push_back({index, value});
            
            if(list_index+1 < nums[index].size())
                minheap.push(Node(index, list_index+1, nums[index][list_index+1]));
        }
        
        vector<int> vis(nums.size(), 0);
        int count = 0, start = 0, end = 0, n = nums.size();
        int rangel = 0, ranger = INT_MAX;
        while(end < arr.size()){
            if(vis[arr[end].first]++ == 0)
                count++;
            // vis[arr[end].first]++;
            
            while(count == n && start <= end){
                // update answer
                int diff = arr[end].second - arr[start].second;
                if(diff < ranger - rangel){
                    rangel = arr[start].second, ranger = arr[end].second;
                }
                
                if(--vis[arr[start].first] == 0)
                    count--;
                start++;
            }
            
            end++;
        }
        
        return {rangel, ranger};
    }
};