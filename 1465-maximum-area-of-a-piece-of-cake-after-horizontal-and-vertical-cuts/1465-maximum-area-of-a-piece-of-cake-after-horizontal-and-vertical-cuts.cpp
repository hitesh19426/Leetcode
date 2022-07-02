class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int height = max(horizontalCuts[0], h-horizontalCuts.back());
        for(int i=0; i<horizontalCuts.size()-1; i++){
            height = max(height, horizontalCuts[i+1] - horizontalCuts[i]);
        }
        
        
        int width = max(verticalCuts[0], w-verticalCuts.back());
        for(int i=0; i<verticalCuts.size()-1; i++){
            width = max(width, verticalCuts[i+1] - verticalCuts[i]);
        }
        
        return ((long long)width*height)%1000'000'007;
    }
};