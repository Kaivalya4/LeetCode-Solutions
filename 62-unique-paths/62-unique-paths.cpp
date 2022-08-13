class Solution {
public:
    int dp[101][101];
    bool isPos(int x , int y , int m , int n){
        if(x == m || y == n)
            return false;
        return true;
    }
    int solve(int i , int j , int m , int n){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans =0;
        if(isPos(i+1,j,m,n))
             ans += solve(i+1,j,m,n);
        if(isPos(i,j+1,m,n))
             ans += solve(i,j+1,m,n);
        dp[i][j] = ans;
        return ans;
    }
    int uniquePaths(int m, int n) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 ,  0 , m , n);
    }
};