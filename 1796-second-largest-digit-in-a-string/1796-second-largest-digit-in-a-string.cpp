class Solution {
public:
    int secondHighest(string s) {
        char largest = '0'-1, second = '0'-1;
        for(char c: s){
            if(isdigit(c)){
                if(c > largest)
                    second = largest, largest = c;
                else if(c > second && c < largest)
                    second = c;
            }
        }
        return (second == '0'-1 ? -1 : second-'0');
    }
};