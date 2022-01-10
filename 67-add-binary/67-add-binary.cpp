class Solution {
public:
    string addBinary(string a, string b) {
        int sum = 0, carry = 0, ptr1 = a.size()-1, ptr2 = b.size()-1;
        string ans = "";
        
        while(ptr1>=0 || ptr2>=0){
            int x = (ptr1<0 ? 0 : a[ptr1]-'0');
            int y = (ptr2<0 ? 0 : b[ptr2]-'0');
            
            ans += (x+y+carry)%2 + '0';
            carry = (x+y+carry)/2;
            
            if(ptr1>=0) ptr1--;
            if(ptr2>=0) ptr2--;
        }
        if(carry){
            ans += '1';
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};