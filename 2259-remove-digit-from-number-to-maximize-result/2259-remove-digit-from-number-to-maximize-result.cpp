class Solution {
public:
    string removeDigit(string number, char digit) {
        string res = "";
        for(int i=0; i<number.size(); i++){
            if(number[i] == digit){
                if(i == number.size() || number[i] < number[i+1])
                    return number.substr(0, i) + number.substr(i+1);
                else
                    res = max(res, number.substr(0, i) + number.substr(i+1));
            }
        }
        return res;
    }
};