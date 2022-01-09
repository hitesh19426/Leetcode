class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, move = 3;
        vector<int> direction = {1, 0, -1, 0, 1};   // 0-right, 1-down, 2-left, 3-up
        
        for(auto &ch: instructions){
            if(ch == 'G'){
                x += direction[move], y += direction[move+1];
            }
            else if(ch == 'L'){
                move--;
                if(move == -1)
                    move += 4;
            }
            else{
                move++;
                if(move == 4)
                    move -= 4;
            }
        }
        
        if((move != 3) || (x==0 && y==0))
            return true;
        return false;
    }
};