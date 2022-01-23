vector<int> fill_numbers(){
    string str = "123456789";
    vector<int> numbers;
    for(int len=2; len<=9; len++){
        for(int i=0; i+len-1<9; i++){
            numbers.push_back(stoi(str.substr(i, len)));
        }
    }
    return numbers;
}

class Solution {
public:
    static vector<int> numbers;
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int &x: Solution::numbers){
            if(x >= low && x <=high){
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};

auto Solution::numbers = fill_numbers();