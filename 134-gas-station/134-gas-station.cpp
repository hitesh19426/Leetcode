class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        for(int start=0; start<gas.size(); start++){
            int move = 0, n = gas.size(), possible = true;
            int total_gas = 0;
            for(int move = 0; move < n; move++){
                int pos = (start+move)%n;
                if(cost[pos] > gas[pos] + total_gas){
                    if(pos+1 <= start)
                        return -1;
                    start = pos, possible = false;
                    break;
                }
                else{
                    total_gas += gas[pos] - cost[pos];
                }
            }
            
            if(possible)
                return start;
        }
        
        return -1;
    }
};

/*

cost[i] > gas[i]


*/