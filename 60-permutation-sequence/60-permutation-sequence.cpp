class Solution {
    int factorial(int n){
        if(n <= 1)
            return 1;
        return n*factorial(n-1);
    }
    
    void helper(string &ans, vector<char>& nums, int k){
        if(nums.empty())
            return;
        
        int n = nums.size();
        int fac = factorial(n-1);
        int group = k/fac, pos = k%fac;
        ans += nums[group];
        nums.erase(nums.begin()+group);
        helper(ans, nums, pos);
    }
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<char> nums;
        for(int i=1; i<=n; i++)
            nums.push_back('0'+i);
        helper(ans, nums, --k);
        return ans;
    }
};

/*

k -> 8 -> 8/6, 8%6 -> 1, 2

0 -> 1 2 3 4
1 -> 1 2 4 3
2 -> 1 3 2 4
3 -> 1 3 4 2
4 -> 1 4 2 3
5 -> 1 4 3 2


6->  2 1 3 4
7->  2 1 4 3
8->  2 3 1 4
9->  2 3 4 1
10-> 2 4 1 3
11-> 2 4 3 1


12-> 3 1 2 4
13-> 3 1 4 2
14-> 3 2 1 4
15-> 3 2 4 1
16-> 3 4 1 2
17-> 3 4 2 1

18-> 4 1 2 3
19-> 4 1 3 2
20-> 4 2 1 2
21-> 4 2 2 1
22-> 4 3 1 2
23-> 4 3 2 1

*/