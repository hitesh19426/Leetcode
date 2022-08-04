class Solution {
    int findScore(vector<int>& tops, vector<int>& bottoms, int target){
        int score = 0, n = tops.size(), top = 0, bottom = 0;
        for(int i=0; i<n; i++){
            if(tops[i] != target){
                if(bottoms[i] != target)
                    return INT_MAX;
                top++;
            }
            else{
                if(bottoms[i] != target)
                    bottom++;
            }
        }
        return min(top, bottom);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = min(findScore(tops, bottoms, tops[0]), findScore(tops, bottoms, bottoms[0]));
        return (ans == INT_MAX ? -1 : ans);
    }
};