class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int value = 0;
        int ans = 0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            if(i == 0){
                value = prices[i];
                continue;
            }
            if(prices[i] < prices[i-1]){
                ans += prices[i-1] - value;
                value = prices[i];
            }
            else{
                if(i == n-1){
                    ans += prices[i] - value;
                }
            }
        }
        return ans;
    }
};