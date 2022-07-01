class Solution {
public:
    int dp[100001][2];
    int solve(int idx , bool picked , vector<int> &nums){
        if(idx == nums.size())
        {
            if(picked)
                return 0;
            return -10000001;
        }
        if(dp[idx][picked] != -1)
            return dp[idx][picked];
        if(picked)
            return dp[idx][picked] = max(0,nums[idx] +solve(idx+1,true,nums));
        return dp[idx][picked] = max(solve(idx +1, false , nums) , nums[idx] + solve(idx +1, true , nums));
    }
    int maxSubArray(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        dp[0][0] = -10000001; 
        dp[0][1] = 0;
        int n = nums.size();
        for(int i=1;i<=n;i++){
            dp[i][1] = max(0 , nums[i-1] + dp[i-1][1]);
            dp[i][0] = max(dp[i-1][0] , nums[i-1] + dp[i-1][1]);
        }
        
        return dp[n][0];
    }
};