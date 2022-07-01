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
        
        return solve(0 , false , nums);
    }
};