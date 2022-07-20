class Solution {
public:
    vector<int> countSteppingNumbers(long long a, long long b) {
        queue<long long> queue;
        for(int i=1; i<10; i++){
            if(i <= b)
                queue.push(i);
        }

        vector<int> ans;
        if(a == 0)
            ans.push_back(0);
        while(!queue.empty()){
            auto num = queue.front();
            queue.pop();

            if(num >= a)
                ans.push_back((int)num);
            int digit = num%10;
            if(digit != 0 && 10*num+digit-1 <= b)
                queue.push(10*num + digit-1);
            if(digit != 9 && 10*num+digit+1 <= b)
                queue.push(10*num + digit+1);
        }

        return ans;
    }
};