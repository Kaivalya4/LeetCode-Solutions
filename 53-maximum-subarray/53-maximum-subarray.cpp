class Solution {
public:
    int dp[100001];
    int maxSubArray(vector<int>& nums) {
        dp[0] = 0;
        int maxi  = nums[0];
        int n = nums.size();
        for(int i=1;i<=n;i++){
            dp[i] = max(nums[i-1] , nums[i-1] + dp[i-1]);
            maxi = max(maxi , dp[i]);
        }
        
        return maxi;
    }
};