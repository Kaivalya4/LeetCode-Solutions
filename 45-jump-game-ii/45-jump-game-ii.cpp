class Solution {
public:
    int dp[10001];
    int solve(int idx , int &n  , vector<int> &nums){
        if(idx>=n-1){
            return 0;
        }
        if(dp[idx] != -1)
            return dp[idx];
        int ans = INT_MAX;
        for(int i=1 ; i<=nums[idx];i++){
            int temp = solve(idx+i,n,nums);
            if(temp != -1){
                ans = min(ans ,  1 + temp);
            }
        }
        if(ans == INT_MAX)
            ans = -1;
        return dp[idx] = ans;
    }
    int jump(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        int n = nums.size();
        int ans = 0;
        return  solve(0 , n  , nums);
    }
};