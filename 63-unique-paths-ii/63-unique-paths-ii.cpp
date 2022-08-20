class Solution {
public:
    int dx[4] = {0,1};
    int dy[4] = {1,0};
    
    int dp[101][101];
    
    bool possible(int &x , int &y , int &n , int &m){
        if(x<0 || y<0 || x>=n || y>=m )
            return false;
        return true;
    }
    
    int solve(int x , int y , int &n , int & m , vector<vector<int>> &grid){
        if(x == n-1 && y == m-1 ){
            if(grid[x][y] == 1)
                return 0;
            return 1;
        }
        if(dp[x][y] != -1)
            return dp[x][y];
        int ans = 0;
        for(int i=0;i<2;i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(possible(newx , newy , n , m ) && grid[newx][newy] == 0){
                ans += solve(newx , newy , n , m  , grid);
            }
        }   
        return dp[x][y] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1)
            return 0;
        memset(dp , -1 , sizeof(dp));
        return     solve(0 , 0 , n , m ,  grid);
    
    }
};