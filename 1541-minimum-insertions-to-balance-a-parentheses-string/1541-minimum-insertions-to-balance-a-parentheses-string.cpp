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
                if(count < 0)
                    count += 2, insertion++;
            }
        }
        return insertion + count;
    }
};