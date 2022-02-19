class Solution {
public:
    bool sameSign(int a, int b){
        return (a>0 && b>0) || (a<0 && b<0);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack(asteroids.size());
        
        int sptr = 0, ptr = 0;
        
        while(ptr < (int)asteroids.size()){
            if(sptr == 0){
                stack[sptr++] = asteroids[ptr++];
            }
            else if(sameSign(stack[sptr-1], asteroids[ptr])){
                stack[sptr++] = asteroids[ptr++];
            }
            else if(stack[sptr-1] < 0 && asteroids[ptr]>0){
                stack[sptr++] = asteroids[ptr++];
            }
            else{
                if(sptr == 0){
                    stack[sptr++] = asteroids[ptr++];
                }
                else if(stack[sptr-1] < -asteroids[ptr]){
                    sptr--;
                }
                else if(stack[sptr-1] == -asteroids[ptr]){
                    sptr--, ptr++;
                }
                else if(stack[sptr-1] > -asteroids[ptr]){
                    ptr++;
                }
            }
        }
        
        stack.resize(sptr);
        return stack;
    }
};