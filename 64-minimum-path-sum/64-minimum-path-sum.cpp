class Solution {
public:
    int n  , m ;
    int dp[201][201] ;
    int solve(int x , int y , vector<vector<int>> &grid){
        if(x == n-1 && y == m-1){
            return grid[x][y];
        }
        
        if(dp[x][y] != -1)
            return dp[x][y];
        
        int down = INT_MAX;
        int right = INT_MAX;
        
        if(x+1<n)
            down = min(down , grid[x][y] + solve(x+1,y,grid)) ;
        if(y+1<m)
            right = min(right , grid[x][y] + solve(x , y+1 , grid));
        return dp[x][y] = min(down , right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 ,grid);
    }
};