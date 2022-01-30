class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        while(--n){
            char lastdigit = str[0];
            string ans = "";
            int count = 0;
            for(int i=0; i<str.size(); i++){
                if(str[i] == lastdigit){
                    count++;
                }
                else{
                    ans += to_string(count) + lastdigit;
                    count = 1;
                    lastdigit = str[i];
                }
            }
            ans += to_string(count) + lastdigit;
            str = ans;
        }
        
        return str;
    }
};