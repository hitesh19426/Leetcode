class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        nth_element(damage.begin(), damage.begin(), damage.end(), greater<int>());
        long long health = max(damage[0]-armor, 0);
        for(int i=1; i<damage.size(); i++)
            health += damage[i];     
        return health+1;
    }
};