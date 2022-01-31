class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int amount = 0;
        for(auto &person: accounts){
            int money = 0;
            for(auto balance: person)
                money += balance;
            amount = max(amount, money);
        }
        return amount;
    }
};