class Solution {
public:
    long long dp[10001][8][8] ;
    long long mod = 1000000007;
    long long solve(int idx , int prev , int prev2 , int &n){
        if(idx == n){
            return 1;
        }
        if(dp[idx][prev][prev2] != -1)
            return dp[idx][prev][prev2];
        long long ans = 0;
        for(int i=1;i<7;i++){
            if(i == prev || i == prev2 || __gcd(prev, i) != 1)
                continue;
            ans = ans +  solve(idx+1, i , prev , n) %mod;
        }
        return dp[idx][prev][prev2] = ans%mod;
    }
    int distinctSequences(int n) {
       
        memset(dp , -1 , sizeof(dp));
        return solve(0, 7 , 7 , n)%mod; 
    }
};