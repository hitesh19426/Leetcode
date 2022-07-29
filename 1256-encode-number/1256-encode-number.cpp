class Solution {
public:
    string encode(int num) {
        string ans = "";
        num++;
        while(num){
            ans += '0' + (num&1);
            num /= 2;
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};