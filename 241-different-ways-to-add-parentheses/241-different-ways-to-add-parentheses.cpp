class Solution {
    unordered_map<int, function<int(int, int)>> mapping{
        {-1, plus<int>()},
        {-2, minus<int>()},
        {-3, multiplies<int>()},
        {-4, divides<int>()}
    };
    
    vector<int> helper(int low, int high, vector<int>& arr){
        if(low == high)
            return {arr[low]};
        
        vector<int> ans;
        for(int i=low+2; i<=high; i+=2){
            auto left = helper(low, i-2, arr);
            auto right = helper(i, high, arr);
            
            for(int x: left){
                for(int y: right){
                    int res = mapping[arr[i-1]](x, y);
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string s) {
        unordered_map<char, int> value{{'+', -1}, {'-', -2}, {'*', -3}, {'/', -4}};
        vector<int> arr;
        for(int i=0; i<s.size(); ){
            if(isdigit(s[i])){
                int num = 0;
                while(i<s.size() && isdigit(s[i]))
                    num = 10*num + (s[i++]-'0');
                arr.push_back(num);
            }
            else{
                arr.push_back(value[s[i++]]);
            }
        }
        
        vector<int> ans;
        return helper(0, arr.size()-1, arr);
    }
};