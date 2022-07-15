class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> sum(m+n, 0);
        
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                sum[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                sum[i+j] += sum[i+j+1]/10;
                sum[i+j+1] %= 10;
            }
        }

        string ans = "";
        for(int i=m+n-1; i>=0; i--){
            ans += '0'+sum[i];
            // int sum = (prod[i]+carry);
            // ans += '0'+sum%10;
            // carry = sum/10;
        }
        
        while(!ans.empty() && ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        
        if(ans.empty())
            return "0";
        return ans;
    }
};