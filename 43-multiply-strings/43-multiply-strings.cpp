class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> prod(m+n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                prod[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
            }
        }

        int carry = 0;
        string ans = "";
        for(int i=m+n-1; i>=0; i--){
            int sum = (prod[i]+carry);
            ans += '0'+sum%10;
            carry = sum/10;
        }
        
        while(!ans.empty() && ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        
        if(ans.empty())
            return "0";
        return ans;
    }
};