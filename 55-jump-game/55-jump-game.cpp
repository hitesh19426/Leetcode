class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lvlStart = 0, lvlEnd = 0, jumps = 0;
        while(lvlStart <= lvlEnd){
            int newStart = lvlEnd+1, newEnd = -1;
            for(int j=lvlStart; j<=lvlEnd; j++){
                newEnd = max(newEnd, j+nums[j]);
                if(newEnd >= nums.size()-1)
                    return true;
            }
            
            lvlStart = newStart, lvlEnd = newEnd;
        }
        
        return false;
    }
};