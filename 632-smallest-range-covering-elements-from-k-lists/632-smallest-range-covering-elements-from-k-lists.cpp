struct Node{
    int index, list_index, value;
    Node(int a, int b, int v) : index(a), list_index(b), value(v) {}
    
    bool operator<(const Node& other) const {
        if(value != other.value)
            return value < other.value;
        if(index != other.index)
            return index < other.index;
        return list_index < other.list_index;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<Node> heap;
        
        for(int i=0; i<nums.size(); i++){
            heap.insert(Node(i, 0, nums[i][0]));
        }
        
        int rangel = 0, ranger = INT_MAX;
        while(!heap.empty()){
            if(heap.size() == nums.size()){
                int left = heap.begin()->value, right = heap.rbegin()->value;
                if(right - left < ranger - rangel)
                    rangel = left, ranger = right;
            }
            
            auto [index, list_index, value] = *heap.begin();
            heap.erase(heap.begin());
            
            if(list_index+1 < nums[index].size())
                heap.insert(Node(index, list_index+1, nums[index][list_index+1]));
        }
        
        return {rangel, ranger};
    }
};

/*
T(n, k) = n*k*logn + n*k
SC(n, k) = n + n*k
*/