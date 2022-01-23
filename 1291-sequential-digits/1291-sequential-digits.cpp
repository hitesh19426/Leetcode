class Solution {
public:
    const vector<int> startnum{0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
    const vector<int> add{0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
    
    int count_digits(int n){
        int count = 0;
        while(n){
            count++;
            n /= 10;
        }
        return count;
    }
    vector<int> sequentialDigits(int low, int high) {
        int lowdigits = count_digits(low), highdigits = count_digits(high);
        
        vector<int> ans;
        for(int i=lowdigits; i<=highdigits && i<=9; i++){
            int num = startnum[i];
            while(num%10 != 0){
                if(num >= low && num<=high){
                    ans.push_back(num);
                }
                num += add[i];
            }
        }
        
        return ans;
    }
};