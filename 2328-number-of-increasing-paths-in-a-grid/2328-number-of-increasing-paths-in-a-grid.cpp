class Solution {
public:
    long long dp[1001][1001];
    bool vis[1001][1001];
    long long mod = 1000000007;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    long long dfs(int x , int y , int &n , int &m , vector<vector<int>> &grid){
        if(vis[x][y]){
            return dp[x][y];
        } 

        vis[x][y] = true;
        dp[x][y] =1ll;
        for(int i=0;i<4;i++){
            int xi = x + dx[i];
            int yi = y + dy[i];
            
            if(xi>=0 && yi>=0 && xi<n && yi<m && grid[x][y] < grid[xi][yi]){
                dp[x][y] = dp[x][y] + dfs(xi,yi,n,m,grid) % mod;
            }
        }
        
        return dp[x][y]%mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        long long ans =0;
        int n = grid.size();
        int m = grid[0].size();
        memset(dp , -1 , sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = ans + dfs(i,j,n,m,grid) %mod;
            }
        }
        
        return ans%mod;
    }
};