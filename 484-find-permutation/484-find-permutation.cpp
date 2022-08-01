class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> permutation(s.size()+1);
        stack<int> stack;
        int curr = 1, ind = 0;
        while(ind <= s.size()){
            if(ind != s.size() && s[ind] == 'D'){
                stack.push(ind++);
            } else{
                permutation[ind] = curr++;
                while(!stack.empty()){
                    permutation[stack.top()] = curr++;
                    stack.pop();
                }
                ind++;
            }
        }
        return permutation;
    }
};