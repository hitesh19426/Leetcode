class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while(i<n && s[i]==' ')
            i++;
        
        if(i==n)
            return 0;
        
        string number = "";
        bool is_positive = true;
        if(s[i] == '+' || s[i]=='-'){
            if(s[i] == '-')
                is_positive = false;
            number += s[i++];
            
        }
        if(i==n)
            return 0;
        // cout << i << endl;
        // cout << isdigit(s[i]);
        while(i<n && isdigit(s[i])){
            number += s[i++];
            // cout << i << endl;
        }
        // cout << number << endl;
        if(number == "" || number == "+" || number=="-")
            return 0;
        try{
            int ans = stoi(number);
            return ans;
        }
        catch(exception e){
            return (is_positive ? INT_MAX : INT_MIN);
        }
        
        return 0;
    }
};