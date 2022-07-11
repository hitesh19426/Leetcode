class Solution {
public:
    int minInsertions(string s) {
        int count = 0, insertion = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                if(count&1)
                    count--, insertion++;
                count += 2;
            }
            else{
                count--;
                if(count < 0){
                    count = 0;
                    if(i != s.size()-1 && s[i+1] == ')')
                        insertion++, i++;
                    else
                        insertion += 2;
                }
            }
        }
        return insertion + count;
    }
};