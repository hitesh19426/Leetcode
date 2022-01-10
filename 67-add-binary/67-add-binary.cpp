class Solution {
public:
    string addBinary(string a, string b) {
        int sum = 0, carry = 0, ptr1 = a.size()-1, ptr2 = b.size()-1;
        string ans = "";
        
        while(ptr1>=0 && ptr2>=0){
            ans += (a[ptr1]-'0'+b[ptr2]-'0'+carry)%2 + '0';
            carry = (a[ptr1]-'0'+b[ptr2]-'0'+carry)/2;
            ptr1--, ptr2--;
        }
        while(ptr1>=0){
            ans += (a[ptr1]-'0'+carry)%2 + '0';
            carry = (a[ptr1]-'0'+carry)/2;
            ptr1--;
        }
        while(ptr2>=0){
            ans += (b[ptr2]-'0'+carry)%2 + '0';
            carry = (b[ptr2]-'0'+carry)/2;
            ptr2--;
        }
        if(carry){
            ans += '1';
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};