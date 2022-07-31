class BIT{
    int size;
    vector<int> bit, arr;
    
    int sum(int ind){
        int res = 0;
        for(++ind; ind>0; ind -= ind&-ind)
            res += bit[ind];
        return res;
    }
public:
    BIT(int n) : size(n+1) {
        bit.assign(size, 0);
        arr.assign(size, 0);
    }
    
    void update(int ind, int val){
        int increase = (val - arr[ind]);
        arr[ind] = val;
        for(++ind; ind<size; ind += ind&-ind)
            bit[ind] += increase;
    }
    
    int sumRange(int left, int right){
        return sum(right) - sum(left-1);
    }
    
};

class NumArray {
    BIT bit;
public:
    NumArray(vector<int>& nums) : bit(BIT(nums.size())) {
        for(int i=0; i<nums.size(); i++)
            bit.update(i, nums[i]);
    }
    
    void update(int index, int val) {
        bit.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return bit.sumRange(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */