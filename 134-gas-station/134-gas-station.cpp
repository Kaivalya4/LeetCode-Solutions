class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ctr = 0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            gas.push_back(gas[i]);
            cost.push_back(cost[i]);
        }
        
        int m = gas.size();
        int g = 0 , c = 0;
        for(int i=0 ; i<m;i++){
            if(ctr == n)
                return i-n ;
            g += gas[i] , c += cost[i] ,  ctr++;
            if(g<c){
                g = 0 , c = 0 , ctr = 0;
            }
        }
        return -1;
    }
};